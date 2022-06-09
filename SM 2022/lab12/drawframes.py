import threading
import cv2
from imutils.video import VideoStream
import time
import imageprocessingalgos as ipa
import imutils

vs = VideoStream(src=0).start()
time.sleep(2.0)
lock = threading.Lock()

img = cv2.imread('MicrosoftTeams-image (8).png')
#img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Klatka oryginalna
outputFrameOriginal = None

# Klatka z odcieniami szarości + rozmyciem Gaussa
outputFrameGrayGauss = None

# Klatka z wykryciem ruchu
outputFrameMotion = None

# Klatka z filtrem Canny
outputFrameCanny = None

# Klatka z filtrem Laplacian
outputFrameLaplacian = None

# Klatka z filtrem Erosion
outputFrameErosion = None

def draw_frames(frameCount):
    global vs, lock
    global outputFrameOriginal, outputFrameMotion, outputFrameGrayGauss, outputFrameCanny
    global outputFrameLaplacian, outputFrameErosion

    md = ipa.SingleMotionDetector(accumWeight=0.1)
    gsg = ipa.GrayscaleAndGauss()
    can = ipa.Canny()
    lapl = ipa.Laplacian()
    eros = ipa.Erosion()

    total = 0

    while True:
        frame = vs.read()
        frame = imutils.resize(frame, width=500)
        orig_frame = frame.copy()
        gray = gsg.applyGrayscaleAndGauss(frame)
        canny = can.applyCanny(frame)
        laplacian = lapl.applyLaplacian(frame)
        erosion = eros.applyErosion(frame)

        # Tekst do oryginalnej klatki
        cv2.putText(orig_frame, "Systemy multimedialne test laboratoria nr. 12 [original frame]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)

        # Tekst do klatki z grayscale i rozmyciem gaussa
        cv2.putText(gray, "Systemy multimedialne test laboratoria nr. 12 [grayscale + gaussian blur]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)

        # Tekst do klatki z wykryciem ruchu
        cv2.putText(frame, "Systemy multimedialne test laboratoria nr. 12 [motion detection]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)

        # Tekst do klatki z filtrem canny
        cv2.putText(canny, "Systemy multimedialne test laboratoria nr. 12 [canny]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)


        # Tekst do klatki z filtrem laplacian
        cv2.putText(laplacian, "Systemy multimedialne test laboratoria nr. 12 [laplacian]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)

        # Tekst do klatki z filtrem erosion
        cv2.putText(erosion, "Systemy multimedialne test laboratoria nr. 12 [erosion]",
                    (10, frame.shape[0] - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (255, 255, 255), 1)

        orig_frame[0:36, 0:200] = img
        img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        gray[0:36, 0:200] = img_gray
        frame[0:36, 0:200] = img
        canny[0:36, 0:200] = img_gray
        laplacian[0:36, 0:200] = img
        erosion[0:36, 0:200] = img


        if total > frameCount:
            motion = md.detect(gray)
            if motion is not None:
                (thresh, (minX, minY, maxX, maxY)) = motion
                cv2.rectangle(frame, (minX, minY), (maxX, maxY),
                              (0, 0, 255), 2)

        md.update(gray)
        total += 1
        with lock:
            outputFrameOriginal = orig_frame.copy()
            outputFrameGrayGauss = gray.copy()
            outputFrameMotion = frame.copy()
            outputFrameCanny = canny.copy()
            outputFrameLaplacian = laplacian.copy()
            outputFrameErosion = erosion.copy()
