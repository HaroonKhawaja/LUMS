clear; close all; clc % clear workspace at the beginning 

dataPath = 'Images/'; % a string for the path to folder where image are placed

imagesList = dir([dataPath '*.png']); % Get a list of all PNG files in the path

imgNo = 1;    % Let0s process first image in the directory, as an example 

im_raw = imread([dataPath imagesList(imgNo).name]); % Load first file as MATLAB array

im_process = im2double(im_raw); % A rescaling function from Image Processing toolbox

% We can process other files in a similar way 

noImg = length(imagesList); % Number of files in folder

row = 683 ;
column = 1022 ;
binary_img = ones(row, column) ;

for indx = 1:noImg       

    im_raw = imread([dataPath imagesList(indx).name]);

    % Task 1.1
    raw_HSV = rgb2hsv(im_raw);

    raw_HSV(:,:,3) = histeq(raw_HSV(:,:,3));
     
    raw_histed_RGB = hsv2rgb(raw_HSV);

    im_processed = im2double(raw_histed_RGB); 
    
    im_processed2 = flipud(im_processed); 

    % Subplots    
    title(sprintf('Original Image %i',indx)); axis image

    subplot(1,2,1); imagesc(im_processed2); 

    title('Result'); axis image
    
    % Task 2.1
    R = im_processed2(:,:,1);
    G = im_processed2(:,:,2);
    B = im_processed2(:,:,3);
    
    NDI = (G-R)./(G+R) ;
    ExG = (2.*G) - R - B;
    ExR = (1.4*R) - G;
    ExB = (1.4*B) - G;
    ExGR = ExG - ExR - ExB ;
    
    % Task 2.2
    vegetation = im_processed2;

    vegetation_grayimage = rgb2gray(vegetation);

    vegetation_green = imsubtract(vegetation(:,:,2), vegetation_grayimage);

    vegetation_mask = im2bw(vegetation_green, 0.075) ;

    rgbImage = cat(3, vegetation_mask, vegetation_mask, vegetation_mask);

    final_image = im_processed2 .* rgbImage;
    subplot(1,2,2)
    imshow(final_image)
    title("Masked image") ;

    pause(0.1); % pause for 1 sec before showing next results
end



