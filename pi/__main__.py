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
    ser.write("1")
    return ""

@app.route("/right")
def right():
    print("right")
    ser.write("2")
    return ""

@app.route("/up")
def up():
    print("up")
    ser.write("3")
    return ""

@app.route("/down")
def down():
    print("down")
    ser.write("4")
    return ""

@app.route("/stop")
def stop():
    print("stop")
    ser.write("5")
    return ""

app.run(port=80, host='192.168.0.2')
