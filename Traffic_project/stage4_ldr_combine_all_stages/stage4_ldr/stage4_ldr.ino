int redled = 3;
int yellowled = 4;
int greenled = 5;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 3;
long duration;
int distance;
int safetyDistance;
const int ldrPin = A0;
char c;
void red();
void yellow();
void green();
void yellow();
void distance_calc();
void LDR();
void setup() 
{
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  //pinMode (11, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600); 
}

void loop() 
{
 //if (Serial.available()>0)
 //{
  
     Serial.print("\n\n***** Traffic Modes***");
     Serial.print("\nR.Regular mode\nP.Pedestrian mode\nN.Night mode");
     Serial.print("\n Enter your choice");
     delay(2000);
     c= Serial.read();
     //Serial.print("\n\n\n\n");
    // Serial.print(c);
     delay(2000);
      
    switch(c)
    {
        case 'R':Serial.print("\n\nYou are in Regular mode");
   do{
   reg: red();
        yellow();
        green();
        yellow(); 
      if (Serial.available()>0)
    {
      c=Serial.read();
    }
    
    }     
  while (c == 'R');
        
        break;
        case 'P':Serial.print("\n\nYou are in Pedestrian mode");
        do
        {
        red();
        yellow();
        green();
        yellow();
        distance_calc();
        if (Serial.available()>0)
    {
      c=Serial.read();
    }
    
    } while (c == 'P');
        break;
        case 'N':Serial.print("\n\nYou are in Night mode");
        do{
          LDR();
        
        distance_calc();
        if (Serial.available()>0)
    {
      c=Serial.read();
    }
    
    }     
  while (c == 'N');
        default:break;//exit(0);
    }
    
 
   // }while(c!=4);
    
   
 //}
}
void green()
{
    digitalWrite (greenled, 1);
    delay (2000);
    digitalWrite (greenled, 0);
}
void red()
{
    digitalWrite (redled, 1);
    delay(2000);
    digitalWrite (redled, 0);
}

void yellow()
{
    digitalWrite (yellowled, 1); 
    delay (1000);
    digitalWrite (yellowled, 0);
} 
void yellow_blink()
{
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);    
    digitalWrite (yellowled, 0);
    delay (100);
}

void distance_calc()
{
 bhavesh: digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  safetyDistance = distance;
   if (safetyDistance <= 10)
  {
    digitalWrite(buzzer, HIGH);
    tone (buzzer,1000,500);
    if(c=='P')
    yellow_blink();
    else
    green();
    goto bhavesh;
  }
  
  //digitalWrite(ledPin, HIGH);
    else
  {
  digitalWrite(buzzer, LOW);
  //digitalWrite(ledPin, LOW);
  }
  
 // Serial.print("Distance");
 // Serial.println(distance);
  
}
void LDR()
{
  bhavesh2:int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

   if (ldrStatus <=300) {

    digitalWrite(ledPin, HIGH);               //turn LED on
    //Serial.println("LDR is DARK, LED is ON");
    digitalWrite (greenled, 0);
    digitalWrite (yellowled, 0);
    goto bhavesh2;
    
   }
  else {
        red();
        yellow();
        green();
        yellow(); 

  }

}


