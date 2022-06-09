from flask import Response
from flask import Flask
from flask import render_template, request
import threading
import drawframes as df
import generateframes as gf

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/video_feed_original")
def video_feed_original():
    return Response(gf.generate_original(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/video_feed_motion_detection")
def video_feed_motion_detection():
    return Response(gf.generate_motion(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/video_feed_grayscale")
def video_feed_grayscale():
    return Response(gf.generate_grayscale(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/video_feed_canny")
def video_feed_canny():
    return Response(gf.generate_canny(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/video_feed_laplacian")
def video_feed_laplacian():
    return Response(gf.generate_laplacian(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


@app.route("/video_feed_erosion")
def video_feed_erosion():
    return Response(gf.generate_erosion(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")


if __name__ == '__main__':
    t = threading.Thread(target=df.draw_frames, args=(
        32,))
    t.daemon = True
    t.start()

    app.run(host="127.0.0.1", port=8080, debug=True,
            threaded=True, use_reloader=False)
df.vs.stop()
