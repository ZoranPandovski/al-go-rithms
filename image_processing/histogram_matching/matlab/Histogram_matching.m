function Histogram_matching(im_file1,im_file2)
    im1= imread(im_file1);
    im2 = imread(im_file2);
    im1 = rgb2gray(im1);
    im2 = rgb2gray(im2);

    v1 = imhist(im1,256);
    v2 = imhist(im2,256);
    mat = tril(ones(256,256),0);
    cum_v1 = mat*v1;
    cum_v2 = mat*v2;

    cum_v1(:,1) = round(((cum_v1(:,1)*1.0)/cum_v1(256,1))*255);
    cum_v2(:,1) = round((cum_v2(:,1)*1.0/cum_v2(256,1))*255);

    for i= 1:256
        I(i,1) = i-1+find(cum_v2(i:256,1)>=cum_v1(i,1),1,'first')-1;
    end
    im3 = im1;
    im3 = I(im1(:,:)+1);
    figure;
    subplot(1,3,1);
    imshow(uint8(im1));
    title('actual image');
    subplot(1,3,2);
    imshow(uint8(im2));
    title('reference image');
    subplot(1,3,3);
    imshow(uint8(im3));
    title('final image');
end


