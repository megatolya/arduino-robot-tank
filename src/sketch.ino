int LEFT = 49;
int RIGHT = 50;
int UP = 51;
int DOWN = 52;
int STOP = 53;
int SPEED = 250;

//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 10; //standby

//Motor A
int PWMA = 3; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

void setup(){
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  Serial.begin(9600);
}

int prevSerialVal;
void loop()
{
    if (Serial.available() > 0) {
        int serialVal = Serial.read();
        if (serialVal != prevSerialVal) {
            prevSerialVal = serialVal;

            if (serialVal == LEFT) {
                stop();
                move(1, SPEED, 0);
                move(2, SPEED, 1);
            }

            if (serialVal == RIGHT) {
                stop();
                move(1, SPEED, 1);
                move(2, SPEED, 0);
            }

            if (serialVal == UP) {
                stop();
                move(1, SPEED, 0);
                move(2, SPEED, 0);
            }

            if (serialVal == DOWN) {
                stop();
                move(1, SPEED, 1);
                move(2, SPEED, 1);
            }

            if (serialVal == STOP) {
                stop();
            }

        }
    }
    delay(1);
}

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){
//enable standby
  digitalWrite(STBY, LOW);
}
