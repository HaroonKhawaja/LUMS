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
    subplot(1,2,1); imagesc(im_raw); 
    
    title(sprintf('Original Image %i',indx)); axis image

    subplot(1,2,2); imagesc(im_processed2); 

    title('Result'); axis image
    
    pause(0.1); % pause for 1 sec before showing next results
end















