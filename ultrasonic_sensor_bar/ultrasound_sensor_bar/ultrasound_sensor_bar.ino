#include <Servo.h> //including the servo module into our software
Servo servo;

//registering pins
const int trigPin = 12;
const int echoPin = 11;

long duration;
int distance;

//millis variables
unsigned long previousMillis = 0; 
const long waitTime = 3000;
bool isBarUp = false; //this will show the bar state

void setup() {
  //waking up arduino and servo
  Serial.begin(9600);
  servo.attach(13);
  servo.write(90); //starting up with a closed bar
  delay(2000);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  digitalWrite(trigPin, LOW); //at first, the sensor does not produce waves
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //after 2us, the sensor produces 8 beats of waves...
  delayMicroseconds(10); //...in the span of 10 us
  digitalWrite(trigPin, LOW); //it stops producing waves

  duration = pulseIn(echoPin, HIGH); //the time between the first send and the first recieve (object found) is the duration 
  distance= duration*0.034/2; //we find the distance by u=2x/t, as the sound travelled two times the distance between the sensor and the object (production and reflection)

  Serial.print("Distance: "); //we print the distance
  Serial.println(distance);

  if (distance>0 && distance<=10){ //id the object is closer than 10cm to the sensor, the bar will open...
    servo.write(180);
    isBarUp = true;
    previousMillis = millis();
    Serial.println("The bar is UP");
  }
  if(isBarUp){
    unsigned long currentMillis = millis();
    if(currentMillis-previousMillis>=waitingTime){
      servo.write(90);
      isBarUp = false;
      Serial.println("The bar is DOWN");
    }
  }
  delay(50);
}
