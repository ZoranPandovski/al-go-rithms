function Histogram_equalization(filename)
    im= imread(filename);
    im_final = im;

	if size(im,3)==3
		for k = 1:3
			im1 = im(:,:,k);
			v1 = imhist(im1,256);
			mat = tril(ones(256,256),0);
			cum_v1 = mat*v1;
			cum_v1(:,1) = round(((cum_v1(:,1)*1.0)/cum_v1(256,1))*255);
			im_final(:,:,k) = cum_v1(im(:,:,k)+1);
		end
	else
		v1 = imhist(im,256);
		mat = tril(ones(256,256),0);
		cum_v1 = mat * v1;
    		cum_v1(:,1) = round(((cum_v1(:,1)*1.0)/cum_v1(256,1))*255);
		im_final = cum_v1(im(:,:)+1);

    figure;
    subplot(1,3,1);
    imshow(uint8(im1));
    title('actual image');
    subplot(1,3,2);
    imshow(uint8(im_final));
    title('final image');
end


