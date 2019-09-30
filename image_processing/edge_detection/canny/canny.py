import cv2
import numpy as np
from matplotlib import pyplot as plt

img1 = cv2.imread('me.jpg',0)
img = cv2.bilateralFilter(img1,5,75,75)
edges = cv2.Canny(img,20,140)

plt.subplot(121),plt.imshow(img,cmap = 'gray')
plt.title('Original Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(edges,cmap = 'gray')
plt.title('Edge Image'), plt.xticks([]), plt.yticks([])

plt.show()
cv2.imwrite('edges.jpg',edges)
