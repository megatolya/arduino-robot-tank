from flask import Flask, url_for, render_template

import serial


ser = serial.Serial('/dev/ttyACM0', 9600)

app = Flask(__name__)

@app.route("/")
def hello():
    return render_template("index.html")

@app.route("/left")
def left():
    print("left")
    ser.write("l")
    return ""

@app.route("/right")
def right():
    print("right")
    ser.write("r")
    return ""

@app.route("/up")
def up():
    print("up")
    return ""

@app.route("/down")
def down():
    print("down")
    return ""

@app.route("/stop")
def stop():
    print("stop")
    ser.write("s")
    return ""

app.run(port=81, host='192.168.1.10')
