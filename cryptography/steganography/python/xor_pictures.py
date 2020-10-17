import cv2
import numpy as np

lemur = cv2.imread("./lemur.png")
flag = cv2.imread("./flag.png")

height, width, color = lemur.shape
answer = np.empty([height, width, color])
for i in range(height):
    for j in range(width):
        for k in range(color):
            answer[i][j][k] = lemur[i][j][k] ^ flag[i][j][k]

cv2.imwrite("answer.png", answer)
