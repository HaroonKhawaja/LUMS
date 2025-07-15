import streamlit as st
import cv2
import pytesseract
import numpy as np
import pandas as pd
import re
import os
import csv
import torch
import torch.nn as nn
import torch.optim as optim
import torchvision.transforms as T
import statistics
from ultralytics import YOLO
import matplotlib.pyplot as plt
from PIL import Image

# Loading YOLO model
yolo_model = YOLO("license_plate_detector.pt")

# Defining helper functions:
def detect_Np(image):
  results = yolo_model(image)

  for result in results[0].boxes.data.tolist():
    x1, y1, x2, y2 = [int(r) for r in result[:4]]
    score, class_id = result[4], int(result[5])

    if class_id == 0:
      cv2.rectangle(image, (x1, y1), (x2, y2), (0, 255, 0), 2)
      label = f"Number plate: {score:.2f}"
      cv2.putText(image, label, (x1-25, y1-10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255, 0, 0), 2)

  cv2.imwrite("./detected_license/sample_test_detection.jpg", image)
  image_info = [x1, y1, x2, y2, score, class_id]
  return image, image_info

def crop_image(detected_np, detected_np_info):
  # Cropping number plate from image
  x1, y1, x2, y2, score, class_id = detected_np_info
  detected_np = detected_np[y1:y2, x1:x2]

  return detected_np

# helper function for countors identification
def find_contours(dimensions, img):
    # Find all contours in the image
    cntrs, _ = cv2.findContours(img.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Retrieve potential dimensions
    lower_width = dimensions[0]
    upper_width = dimensions[1]
    lower_height = dimensions[2]
    upper_height = dimensions[3]

    # Check largest 5 or 15 contours for license plate or character respectively
    cntrs = sorted(cntrs, key=cv2.contourArea, reverse=True)[:15]

    ii = cv2.imread('contour.jpg')

    x_cntr_list = []
    img_res = []
    widths = []
    heights = []
    contours = []  # Store contour coordinates here

    # Calculate the middle line of the license plate
    middle_line = img.shape[0] // 2

    # Sort contours based on x-coordinate and then on y-coordinate
    sorted_cntrs = sorted(cntrs, key=lambda c: (c[0][0][0], c[0][0][1]))

    # Separate contours above and below the middle line
    above_middle = []
    below_middle = []
    for cntr in sorted_cntrs:
        x, y, w, h = cv2.boundingRect(cntr)

        if y < middle_line:
            above_middle.append((x, y, w, h, cntr))
        else:
            below_middle.append((x, y, w, h, cntr))

    # Sort contours from left to right
    above_middle = sorted(above_middle, key=lambda c: c[0])
    below_middle = sorted(below_middle, key=lambda c: c[0])

    # Process contours above the middle line
    for x, y, w, h, cntr in above_middle:
        if w > lower_width and w < upper_width and h > lower_height and h < upper_height:
            char = img[y:y+h, x:x+w]
            white_pixels = np.sum(char == 255)
            total_pixels = char.size
            white_percentage = (white_pixels / total_pixels) * 100

            if white_percentage >= 25:
                x_cntr_list.append((x, y))  # stores the (x, y) coordinates of the character's contour
                widths.append(w)
                heights.append(h)
                contours.append((x, y, x+w, y+h))  # Append contour coordinates

                char_copy = np.zeros((44, 24))
                # Extracting each character using the enclosing rectangle's coordinates.
                char = cv2.resize(char, (20, 40))

                cv2.rectangle(ii, (x, y), (x+w, y+h), (50, 21, 200), 2)
                plt.imshow(ii, cmap='gray')

                # Make result formatted for classification: invert colors
                char = cv2.subtract(255, char)

                # Resize the image to 24x44 with a black border
                char_copy[2:42, 2:22] = char
                char_copy[0:2, :] = 0
                char_copy[:, 0:2] = 0
                char_copy[42:44, :] = 0
                char_copy[:, 22:24] = 0

                img_res.append(char_copy)  # List that stores the character's binary image (unsorted)

    # Process contours below the middle line
    for x, y, w, h, cntr in below_middle:
        if w > lower_width and w < upper_width and h > lower_height and h < upper_height:
            char = img[y:y+h, x:x+w]
            white_pixels = np.sum(char == 255)
            total_pixels = char.size
            white_percentage = (white_pixels / total_pixels) * 100

            if white_percentage >= 25:
                x_cntr_list.append((x, y))  # stores the (x, y) coordinates of the character's contour
                widths.append(w)
                heights.append(h)
                contours.append((x, y, x+w, y+h))  # Append contour coordinates

                char_copy = np.zeros((44, 24))
                # Extracting each character using the enclosing rectangle's coordinates.
                char = cv2.resize(char, (20, 40))

                cv2.rectangle(ii, (x, y), (x+w, y+h), (50, 21, 200), 2)
                plt.imshow(ii, cmap='gray')

                # Make result formatted for classification: invert colors
                char = cv2.subtract(255, char)

                # Resize the image to 24x44 with a black border
                char_copy[2:42, 2:22] = char
                char_copy[0:2, :] = 0
                char_copy[:, 0:2] = 0
                char_copy[42:44, :] = 0
                char_copy[:, 22:24] = 0

                img_res.append(char_copy)  # List that stores the character's binary image (unsorted)

    # Calculate median width and height
    median_width = statistics.median(widths)
    median_height = statistics.median(heights)

    # Filter characters based on width and height deviation from the median
    filtered_img_res = []
    filtered_contours = []
    for char, contour in zip(img_res, contours):
        x1, y1, x2, y2 = contour
        if ((x2 - x1) >= 0.70 * median_width) and ((x2 - x1) <= 1.3 * median_width) and ((y2 - y1) >= 0.70 * median_height) and ((y2 - y1) <= 1.3 * median_height):
            filtered_img_res.append(char)
            filtered_contours.append(contour)

    # Remove contours with a distance of more than 15 pixels between them
    remaining_contours = []
    remaining_filtered_img_res = []
    if len(filtered_contours) > 1:
        center_x = img.shape[1] / 3
        distance = 0
        count = 1
        for i in range(1, len(filtered_contours)):
            if count >= len(filtered_contours):
                break
            x1_prev, _, x2_prev, _ = filtered_contours[count - 1]
            x1_curr, _, x2_curr, _ = filtered_contours[count]
            distance = x1_curr - x2_prev
            if distance <= -175:
                count += 1
                continue
            elif distance <= 15:
                remaining_contours.append(filtered_contours[count - 1])
                remaining_filtered_img_res.append(filtered_img_res[count - 1])
                count += 1
            elif x1_curr < center_x:
                remaining_contours.append(filtered_contours[count])
                remaining_filtered_img_res.append(filtered_img_res[count])
                count +=2
            elif x1_curr >= (center_x * 2):
                remaining_contours.append(filtered_contours[count - 1])
                remaining_filtered_img_res.append(filtered_img_res[count - 1])
                count +=2
            else:
                remaining_contours.append(filtered_contours[count - 1])
                remaining_filtered_img_res.append(filtered_img_res[count - 1])
                count += 1

        remaining_contours.append(filtered_contours[-1])
        remaining_filtered_img_res.append(filtered_img_res[-1])

    plt.show()

    return np.array(remaining_filtered_img_res)

# Find characters in the resulting images
def segment_characters(image):
    # Preprocess cropped license plate image    
    # Resizing the image
    resized_image = cv2.resize(image, (333, 100))

    # Grey scale conversion
    gray_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2GRAY)
    gray_image = gray_image * 255

    # Applying a threshold to binarize the grey scale image
    threshold_value = 190
    ret, thresh_image = cv2.threshold(gray_image, threshold_value, 255, cv2.THRESH_BINARY+cv2.THRESH_OTSU)

    # Applying some morphological operators
    kernel_3x3 = np.ones((3, 3), np.uint8)
    kernel_4x4 = np.ones((4, 4), np.uint8)

    dilated_image = cv2.dilate(thresh_image, kernel_3x3, iterations=1)
    eroded_image = cv2.erode(dilated_image, kernel_4x4, iterations=1)
    dilated_image = cv2.dilate(eroded_image, kernel_4x4, iterations=1)
    eroded_image = cv2.erode(dilated_image, kernel_3x3, iterations=1)
    image = eroded_image

    # Making borders white
    border_thickness = 5
    border = border_thickness * 2
    LP_WIDTH, LP_HEIGHT = image.shape[:2]
    
    image[0:border, :] = 255
    image[:, 0:border] = 255
    image[LP_WIDTH-border:, :] = 255
    image[:, LP_HEIGHT-border:] = 255

    # Estimations of character contours sizes of cropped license plates
    dimensions = [LP_WIDTH/10,
                  2*LP_WIDTH/2.5,
                  LP_HEIGHT/20,
                  2*LP_HEIGHT/2.5]
    img_binary_lp = image
    cv2.imwrite('contour.jpg', img_binary_lp)

    # Get contours within cropped license plate
    char_list = find_contours(dimensions, img_binary_lp)

    return char_list

# Define the convolutional neural network model
class CNNNet(nn.Module):
    def __init__(self, in_channels, num_classes):
        super(CNNNet, self).__init__()

        # Convolutional layers
        self.conv_l1 = nn.Conv2d(in_channels=in_channels, out_channels=32, kernel_size=3)

        self.conv_l2 = nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3)

        self.conv_l3 = nn.Conv2d(in_channels=64, out_channels=64, kernel_size=3)

        # Pooling layer
        self.maxpool = nn.MaxPool2d(kernel_size=2, stride=2)

        # Fully connected layers
        self.fc_1 = nn.Linear(in_features=(30976), out_features=num_classes)

        self.relu = nn.ReLU()

    def forward(self, x):
        # Apply convolutional layers with ReLU activation and pooling
        x = self.conv_l1(x)
        x = self.relu(x)

        x = self.conv_l2(x)
        x = self.relu(x)

        x = self.conv_l3(x)
        x = self.relu(x)

        # Dynamically flatten the output from the conv layers
        x = x.view(x.size(0), -1)

        # Fully connected layers with ReLU activation
        x = self.fc_1(x)

        # Output layer (log_softmax for classification)
        output_layer = nn.LogSoftmax(dim=1)(x)

        return output_layer

# Loading the pre-trained CNN model
device = "cuda" if torch.cuda.is_available() else "cpu"
cnn_net_model = CNNNet(in_channels=1, num_classes=36).to(device)
cnn_net_model.load_state_dict(torch.load('./cnn_net.pt'))
cnn_net_model.eval()

def fix_dimension(img):
    img = cv2.resize(img, (28, 28))
    if len(img.shape) == 2:
        img = np.expand_dims(img, axis=2)
    
    return img

def show_results(characters, char):
    dic = {i: c for i, c in enumerate(characters)}
    output = []
    for i, ch in enumerate(char):
        image = fix_dimension(ch)
        image = T.ToTensor()(image) / 255
        image = T.functional.invert(image)
        if len(image.shape) == 3:
            image = image.expand(1, -1, -1, -1)
        with torch.no_grad():
            outputs = cnn_net_model(image.float().to(device)).detach().cpu()

        output_idx = int(np.argmax(outputs, axis=1))
        output.append(dic[output_idx])

    plate_number = ''.join(output)
    return plate_number

# streamlit as st app title
st.title("License Plate Detection and Recognition Software")

# streamlit as st app widget
uploaded_file = st.file_uploader("Choose an image file", type=["png", "jpg", "jpeg"])

# Initializing regex
yyyy_mm_dd= r"(\d{4})-(\d{2})-(\d{2})"
hh_mm_ss = r"_(\d{2})-(\d{2})"
yyyy = r"(\d{4})"

# CSV file for car logs
csv_file = "car_logs.csv"

if uploaded_file:
    st.image(uploaded_file, caption="Uploaded Image", use_column_width=True)
    image = Image.open(uploaded_file)
    image = np.array(image)

    st.subheader("1. Detecting Number Plate . . .")
    detected_np, detected_np_info = detect_Np(image)
    st.image(detected_np, caption="Detected License Plate", use_column_width=True)

    st.subheader("2. Segmenting Characters From Number Plate . . .")
    cropped_np = crop_image(detected_np, detected_np_info)
    chars = segment_characters(cropped_np)

    st.subheader("3. Recognizing Characters . . .")
    characters = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    license_plate_number = show_results(characters, chars)
    st.write(f"Detected License Plate Numbser: {license_plate_number}")

    st.subheader("4. Saving Results . . .")
    file_path = uploaded_file.name
    match_time_stamp_1 = re.search(yyyy_mm_dd, file_path)
    time_stamp = ""
    time_stamp_1 = ""
    time_stamp_2 = ""

    if match_time_stamp_1:
        time_stamp_1 = match_time_stamp_1.group(0)
        match_time_stamp_2 = re.search(hh_mm_ss, file_path)

        if match_time_stamp_2:
            time_stamp_2 = match_time_stamp_2.group(0)
            time_stamp_2 = time_stamp_2.replace("_", " ")
            time_stamp_2 = time_stamp_2.replace("-", ":") + ":00"
            time_stamp = time_stamp_1 + time_stamp_2

    else:
        match_time_stamp_3 = re.search(yyyy, file_path)
        if match_time_stamp_3:
            time_stamp = match_time_stamp_3.group(0)

    if st.button("Save to CSV"):
        with open(csv_file, "a", newline="") as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow([license_plate_number, time_stamp, file_path])
        st.success("Saved To CSV")