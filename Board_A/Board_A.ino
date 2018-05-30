//board A

int buzzer = 11;
int LED_Yellow = 4;
int LED_Red = 3;
int LED_Green = 5;

const int sensorPin = 12;
//unsigned int sensorValue = 0;

void setup()
{
   pinMode(LED_Red, OUTPUT);
   pinMode(LED_Green, OUTPUT);
   pinMode(LED_Yellow, OUTPUT);
   pinMode(buzzer, OUTPUT);
   
   
  Serial.begin(9600);
  Serial1.begin(9600);
  while (!Serial1);
}

char bhav;
int count = 0;
int count2 = 9;
void loop()
{ 
int sensorValue = analogRead(sensorPin);


  if (Serial1.available())
  {
    bhav = Serial1.read();
    
if(bhav == 'n')
{
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Yellow, LOW);
  
}

else if (bhav == 'e')
{
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, HIGH);
digitalWrite(LED_Yellow, LOW);
  
}
// Night Mode
else if (bhav == 'i' && sensorValue <= 450)
{
  
  tone(buzzer,500,500);
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Yellow, LOW);
  
   delay(100);

  
  count2--;

   if(count2>0){
     count--;
 } 
 //else if (count2==18){
// goto bhavesh;
//     count =0;
//     count2 =0;
// } else{
//bhavesh:     count--;
}
  
delay(1000);

   noTone(buzzer);
  
}
else
{
  //for(int i=0;i<10;i++)
  //{
digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Yellow, HIGH);
//}
}
//}
    Serial.write(bhav);
  }

////}
