#include <Servo.h>

Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(11);
}

int prevSerialVal;
void loop()
{
    int servoVal = 90;
    bool change = false;
    //stop="s"=115
    //right="r"=114
    //left="l"=108
    int serialVal = Serial.read();
    if (serialVal != prevSerialVal) {
        prevSerialVal = serialVal;
        if (serialVal == 114) {
            servoVal = 1;
            change = true;
        }

        if (serialVal == 108) {
            change = true;
            servoVal = 179;
        }

        if (serialVal == 115) {
            change = true;
            servoVal = 90;
        }

        //  servoVal = map(xVal, 0, 1023, 0, 180);

        servo.write(servoVal);
    }
    delay(400);
}
