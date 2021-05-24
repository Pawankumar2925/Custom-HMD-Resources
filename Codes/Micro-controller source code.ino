#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>
const int button = 6;
const int led = 7;  
int flag=0;                   
int temp=0;
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int count;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT); 
  pinMode(button,INPUT);         // define button as an input 
  digitalWrite(button,HIGH);
  digitalWrite(led,LOW);
  Mouse.begin();
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}

void loop() {
if((!digitalRead(button)) and temp==0){
    flag=1-flag;
    delay(500);
//    temp=1;
    }
digitalWrite(led,flag);
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
Serial.print("Var X:");Serial.print(gz);
Serial.print(" Var Y:");Serial.println(gx);
  vx = (gy+660)/1500;  // 
  vy =-(gx+200)/800; // 
//  
Serial.print("Var X:");
Serial.print(vx);
Serial.print(" Var Y:");
Serial.println(vy);
 Mouse.move(vx, vy);

 if(flag){
  Mouse.press();
  
  }


  else{
    Mouse.release();
    }
  }
