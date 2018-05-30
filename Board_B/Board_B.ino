// board B
#include <SoftwareSerial.h>
#define ECHOPIN 9
#define TRIGPIN 8


void setup()
{
  Serial1.begin(9600);///
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop()
{

  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float distance = pulseIn(ECHOPIN, HIGH)/58; 
 //Serial.print(distance);
 // int b=int(distance);
 // Serial.print(b);
// Serial.println("cm");
 delay(100);

if(distance <= 10)
{
  Serial1.write('i'); // 
 // delay(1000);
  delay(100);
}
else if(distance > 10 && distance < 20)
 {
  Serial1.write('e');
  delay(100);
 // delay(1000);
}
else 
{
Serial1.write('n');
  delay(100);
}
}

}

