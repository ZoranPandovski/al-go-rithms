import cv2
new_path = 'C:\\Anaconda3\\pkgs\\opencv-3.4.4-py37hb76ac4c_1203\\Library\\etc\\haarcascades\\'
#use your own location for haar casscades
face_cascade = cv2.CascadeClassifier(new_path + 'haarcascade_frontalface_default.xml')
cap=cv2.VideoCapture(0)
while (True):
    _, img=cap.read()
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces=face_cascade.detectMultiScale(gray,1.1,4)
    for(x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
    cv2.imshow('img',img)
   
    if  cv2.waitKey(10) & 0xff == ord("q"):
        break
cap.release()
cv2.destroyAllWindows()