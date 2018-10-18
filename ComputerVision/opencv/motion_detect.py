import cv2

def diffImg(t0, t1, t2):
  d1 = cv2.absdiff(t2, t1)
  d2 = cv2.absdiff(t1, t0)
  return cv2.bitwise_and(d1, d2)

cam = cv2.VideoCapture(0)

winName = "Motion Indicator"
cv2.namedWindow(winName)

# Read three images first:
t_minus=cam.read()[1]
t=cam.read()[1]
t_plus=cam.read()[1]

while True:
  cv2.imshow( winName, diffImg(t_minus, t, t_plus) )

  # Read next image
  t_minus = t
  t = t_plus
  t_plus = cam.read()[1]

  key = cv2.waitKey(10)
  if key == 27:
    cv2.destroyWindow(winName)
    break
cam.release()
print("Goodbye")

cv2.GaussianBlur()
