int redled = 3;
int yellowled = 4;
int greenled = 5;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
long duration;
int distance;
int safetyDistance;

void setup() 
{
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() 
{
     //stopped  
    green();
    yellow();
    red();
    yellow();
    distance_calc();
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
void yellowblink()
{
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);    
    digitalWrite (yellowled, 0);
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);
    digitalWrite (yellowled, 0);
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);
    digitalWrite (yellowled, 0);
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);
    digitalWrite (yellowled, 0);
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);
    digitalWrite (yellowled, 0);
}
void distance_calc()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  safetyDistance = distance;
   if (safetyDistance <= 5)
  {
  digitalWrite(buzzer, HIGH);
    delay (100);
    digitalWrite (yellowled, 1);
    delay (100);    
    digitalWrite (yellowled, 0);
    delay (100);
  }
  //{yellowblink();}
  //digitalWrite(ledPin, HIGH);
    else
  {
  digitalWrite(buzzer, LOW);
  //digitalWrite(ledPin, LOW);
  }
  
  Serial.print("Distance");
  Serial.println(distance);
  
}

