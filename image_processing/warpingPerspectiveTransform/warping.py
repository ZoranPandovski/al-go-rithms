from __future__ import print_function
##################################################################
##################################################################
# Importing necessary packages

import numpy as np
import cv2
import matplotlib.pyplot as plt


##################################################################
# Reading the input image
orig_img = cv2.imread('LA.jpg', cv2.IMREAD_UNCHANGED)

rows,cols,ch = orig_img.shape # Calculating image dimensions

print(rows, cols)
'''
# Creating an alpha channel transparent overlay for the grids
img = np.zeros((rows, cols, 3), dtype = "uint8")
'''

##################################################################
##################################################################
# Capturing the source points

print("Order to be followed while selecting points:")
'''
TL Top    Left
TR Top    Right
BR Bottom Right
BL Bottom Left
'''
print("TL TR BR BL")

cv2.namedWindow('image', cv2.WINDOW_NORMAL) # Creating a resizable image window

##################################################################
# Capturing the mouse (X, Y) coordinates when the left button is DOUBLE CLICKED

def mouse_click(event, x, y, flags, param):
    global mouseX, mouseY

    if event == cv2.EVENT_LBUTTONDBLCLK: # Left Mouse Button Double Clicked Flag, consult cv2 documentation for further details
        cv2.circle(orig_img,(x,y),10, (255,0,0),-1) # Draw a blue point when double clicked
        mouseX, mouseY = x, y # Storing source points temporarily in the global variables x, y

# Capturing the mouse movement in the 'image' Window and relaying it to the mouse_click function
cv2.setMouseCallback('image', mouse_click)

##################################################################
# Defining a list to store the source points clicked by the user

pts1 = [] # Input points from the source image


'''
Once you double click on a source point, a blue circle appears.
To append it to the pts list, Press 'a' on the keyboard.
Repeat the above two steps to find at least 4 source points.
Press ESC to continue to move on to the next step.
'''

while(1):
    cv2.imshow('image',orig_img)
    k = cv2.waitKey(20) & 0xFF
    if k == 27:
        pts1 = np.float32([pts1]) # When ESC is pressed, the pts1[] is converted into an numpy ndarray of points
        break
    elif k == ord('a'): # If 'a' is pressed, the values in the global variables are appended to the source points list
        pts1.append([mouseX, mouseY])


# Initializing the pts2[] to contain the destination points
pts2 = np.float32([[0, 0], [cols, 0], [cols, rows], [0, rows]])


##################################################################
##################################################################
'''
 To Compute the perspective transform, M,
 given the source and destination points
 we use cv2.getPerspectiveTransform(src,dst).

 To compute the inverse perspective transform, invPM,
 we use cv2.getPerspectiveTransform(dst,src)
'''


M = cv2.getPerspectiveTransform(pts1,pts2) # Computing the Perspective Transform Matrix
pdst = cv2.warpPerspective(orig_img, M, (cols,rows)) # Storing the warped image in pdst


cv2.namedWindow('Pdst', cv2.WINDOW_NORMAL)
cv2.imshow('Pdst', pdst)
cv2.waitKey(0)
