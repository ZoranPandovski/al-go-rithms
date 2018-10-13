# Convolutional Neural Network
Computer Vision (CV) allows computer programs to process images and videos to recognize the environment. It is heavily used in 
applications like face recognition or helping self-driving cars identify cars or pedestrians. Convolutional Neural Networks (CNNs)
are at the heart of most CV applications. CNNs use the convolution operation to transform input images into outputs. A single step 
of convolution multiplies and sums the pixel values of an image with the values of a filter. This filter can be of shape 3x3. Next,
the filter is shifted to a different position and the convolutional step is repeated until all pixels are processed at least once.
The resulting matrix eventually detects edges or transitions between dark and light colors and eventually more complex forms. The 
more filters you apply, the more details the CNN is capable to recognize.<br>
![alt WORKFLOW](https://github.com/BAJUKA/al-go-rithms/blob/master/deep_learning/python/CNN/image/cnn.gif)<br>
## Components of Convolutional Neural Network
<b>1. Pooling </b><br>
The first secret sauce that has made CNNs very effective is pooling. Pooling is a vector to scalar transformation that operates on 
each local region of an image, just like convolutions do, however, unlike convolutions, they do not have filters and do not compute
dot products with the local region, instead they compute the average of the pixels in the region (Average Pooling) or simply picks 
the pixel with the highest intensity and discards the rest (Max Pooling). The very idea of pooling can seem counter-productive as 
it leads to loss of information, however it has proven to be very effective in practice because, it makes covnets invariant to 
variations in the presentation of an image and it also reduces the effects of background noise.<br>
<b>2. Dropouts</b><br>
Overfitting is a phenomenon whereby a network works well on the training set, but performs poorly on the test set. This is often 
due to excessive dependence on the presence of specific features in the training set. Dropout is a technique for combating over-
fitting. It works by randomly setting some activations to 0, essentially killing them. By doing this, the network is forced to 
explore more ways of classifying the images instead of over-depending on some features.<br>
<b>3. Batch Normalization</b><br>
A major problem with neural networks is vanishing gradients. This is a situation whereby the gradients become too small, hence, 
training surfers terribly. Ioffe and Szegedy from Google Brain discovered that this was largely due to internal covariate shift, a 
situation that arises from the change data distribution as information flows through the network. What they did was to device the 
technique known as batch normalization. This works by normalizing every batch of the image to have zero mean and unit variance.<br>
## Some popular CNN Architectures:
1. AlexNet
2. VGG-16
3. VGG-19
4. Inception-v3

