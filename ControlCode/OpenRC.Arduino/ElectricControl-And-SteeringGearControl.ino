#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 700
#define MOTOR_PIN 10 //九号引脚是紫色的引脚 也就是D9
#define DUOJI_PIN 9//舵机引脚

int idle = (MAX_SIGNAL + MIN_SIGNAL) / 2;
int slow = (MAX_SIGNAL - idle) / 3;
int med = slow * 2;
int fast = MAX_SIGNAL;
int callibrate = 2;

int pos = 0;    // 角度存储变量

Servo motor;
Servo duoji;
void setup() {

  motor.attach(MOTOR_PIN);
  duoji.attach(DUOJI_PIN);//舵机初始化
  Serial.begin(9600);

  if (callibrate != 1) {
    motor.writeMicroseconds(idle);
  }
}

void loop() {
  /*
     Testing phase
  */


  if (Serial.available() > 0)
  {
    String comdata = "";
    while (Serial.available() > 0)
    {
      comdata += char(Serial.read());
      delay(2);
    }
    
    int index = comdata.indexOf(' ');

    String lastText = comdata.substring(index);

    String firstText = comdata.substring(0, index);

    int dJIAODU = firstText.toInt();

    int SUDU = lastText.toInt();

    Serial.println(dJIAODU);

    Serial.println(SUDU);

    Serial.println(comdata);

    motor.writeMicroseconds(SUDU);

    duoji.write(dJIAODU);
    
    delay(500);
  }
}