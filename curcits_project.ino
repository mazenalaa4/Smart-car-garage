#include <Servo.h>
Servo s1;
char reading;
int led =8;
void setup() {
  // put your setup code here, to run once:
s1.attach(6);
Serial.begin(9600);
s1.write(0);
pinMode(led,OUTPUT);
digitalWrite(13,0);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0) {
reading=Serial.read();
switch(reading){
case 'F':
digitalWrite(13,1);
for(int i=0;i<=180;i++)
{s1.write(i);
delay(25);}
break;
case 'S': 
for(int i=180;i>=0;i--)
{s1.write(i);
delay(25);}
digitalWrite(13,0);
break;
}
}
}
