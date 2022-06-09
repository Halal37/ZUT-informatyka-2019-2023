import cv2
import drawframes as df


def generate_original():
    while True:
        with df.lock:
            if df.outputFrameOriginal is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameOriginal)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')


def generate_grayscale():
    while True:
        with df.lock:

            if df.outputFrameGrayGauss is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameGrayGauss)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')


def generate_motion():
    while True:
        with df.lock:
            if df.outputFrameMotion is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameMotion)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')


def generate_canny():
    while True:
        with df.lock:
            if df.outputFrameCanny is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameCanny)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')


def generate_laplacian():
    while True:
        with df.lock:
            if df.outputFrameLaplacian is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameLaplacian)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')


def generate_erosion():
    while True:
        with df.lock:
            if df.outputFrameErosion is None:
                continue

            (flag, encodedImage) = cv2.imencode(".jpg", df.outputFrameErosion)

            if not flag:
                continue

        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' +
               bytearray(encodedImage) + b'\r\n')
