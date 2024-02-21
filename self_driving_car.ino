#include<NewPing.h>
#include<AFMotor.h>
#include<Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo ser;
int Speed=250;

int trigg = 52;
int echo = 50;
int max_distance = 400;
int distance;
long duration;

NewPing sonar(trigg, echo, max_distance);

void setup() {
  Serial.begin(9600);
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);
  ser.attach(10);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);

}

void loop() 
{
//  if(lookforward<=20)
//  {
//    if(lookright()<=20)
//    {
//      if(lookleft<=20)
//      {
//        juststop();
//        gobackward();
//      }
//      else
//      {
//        moveleft();
//        goforward();
//      }
//    }
//      else
//     {
//      moveright();
//      goforward(); 
//     }
//  }
//  else
//  {
//    goforward();
//  }
//  

//goforward();
//delay(5000);
//juststop();
//delay(2000);
//gobackward();
//delay(5000);
//juststop();
//delay(2000);
moveright();
delay(5000);
juststop();
delay(2000);
moveleft();
delay(5000);
}

int lookforward()
{
  ser.write(90);
  delay(100);
  distance=calculatedistance();
  return distance;
}

int lookright()
{
  ser.write(150);
  delay(100);
  distance = calculatedistance();
  return distance;
}

int lookleft()
{
  ser.write(20);
  delay(100);
  distance = calculatedistance();
  return distance;
}
int calculatedistance()
{
  int cm = sonar.ping_cm();
  return cm;
}

void goforward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
}

void gobackward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  delay(500);
}
void moveright()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(500);
}

void moveleft()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(500);
}

void juststop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(500);
}
