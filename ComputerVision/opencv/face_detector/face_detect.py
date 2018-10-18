import cv2

face_cas = cv2.CascadeClassifier("cas/haarcascade_frontalface_default.xml")
eye_cas = cv2.CascadeClassifier("cas/haarcascade_eye.xml")
writer = None


def facedet(gray, im):
    face = face_cas.detectMultiScale(gray, 1.3, 5)

    for x, y, w, z in face:
        cv2.rectangle(im, (x, y), (x+w, y+z), (0, 0, 0), 2)

    return im


vid = cv2.VideoCapture(0)
while(1):
    ret, im = vid.read()
    gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
    if writer is None:
        fourcc = cv2.VideoWriter_fourcc(*"MJPG")
        writer = cv2.VideoWriter("output/output.mp4", fourcc, 20,
                                 (im.shape[1], im.shape[0]), True)

    im = facedet(gray, im)
    cv2.imshow("img", im)
    if writer is not None:
        writer.write(im)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

vid.release()
cv2.destroyAllWindows()
if writer is not None:
    writer.release()
