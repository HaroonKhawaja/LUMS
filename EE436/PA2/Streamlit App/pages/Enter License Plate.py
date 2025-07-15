import streamlit as st
import pandas as pd
import os
from PIL import Image

st.title("Generate Car Images")
st.markdown("Enter license plate number and retreive log records and car images")

csv_file = "car_logs.csv"
license_df = None

try:
    df = pd.read_csv(csv_file, names=["License Plate", "Timestamp", "File Name"])
except FileNotFoundError:
    st.error("CSV file not found.")
    df = pd.DataFrame(columns=["License Plate", "Timestamp", "File Name"])

if not df.empty:
    license_numbers = df["License Plate"].unique().tolist()
    selected_license = st.selectbox("Select License Number", options=license_numbers, placeholder="Choose and option")
    
    if st.button("Submit"):
        if selected_license:
            license_df = df[df["License Plate"] == selected_license]

            if license_df.empty:
                st.warning(f"No license plate found for number plate: {selected_license}")
            else:
                st.subheader(f"1. Results for license plate: {selected_license}")
                st.write(license_df)
        else:
            st.error(f"Please select a valid license plate number.")
else:
    st.error("The CSV file is empty/invalid.")

if license_df is not None:
    st.subheader("2. Retreiving Car Images")
    for index, row in license_df.iterrows():
        file_name = row["File Name"]
        file_path = os.path.join("./Images", file_name)

        if os.path.exists(file_path):
            st.image(Image.open(file_path), use_column_width=True)
        else:
            st.warning(f"Image \"{file_name}\" not found.")
