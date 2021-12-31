// Kaapo's Ultrasonic sensor project using "Arduino Uno" board and Ultrasonic sensor "HC-SR04". 
// Date 2021-10-12  
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04 
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04 

#define echoP2 4
#define trigP2 5

// defines variables 
long duration;// variable for the duration of sound wave travel 
long duration2;
int distance; // variable for the distance measurement 
int distance2;
int led = 13;
int vihrled = 8;
  
void setup() {
  pinMode(led, OUTPUT);
  pinMode(vihrled, OUTPUT);
    
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT 

  pinMode(trigP2, OUTPUT); // Sets the trigPin as an OUTPUT 
  pinMode(echoP2, INPUT); // Sets the echoPin as an INPUT 

  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor 
  Serial.println("with Arduino UNO R3"); 
}
void loop() { 
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  digitalWrite(trigP2, LOW);
  delayMicroseconds(2); 
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  digitalWrite(trigP2, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigP2, LOW); 
  duration2 = pulseIn(echoP2, HIGH);

  // Reads the echoPin, returns the sound wave travel time in microseconds 
 // duration2 = pulseIn(echoP2, HIGH);
  // Calculating the distance 
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back) 
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back) 

if (distance < 30 )
  digitalWrite(led, HIGH);
else
  digitalWrite(led, LOW);

if (distance2 < 50 )
  digitalWrite(vihrled, HIGH);
else
  digitalWrite(vihrled, LOW);




  // Displays the distance on the Serial Monitor 
  Serial.print("Lähin objekti edessä on ");
  Serial.print(distance); 
  Serial.println(" senttimetrin päässä"); 
  Serial.print("Lähin objekti takana on ");
  Serial.print(distance2); 
  Serial.println(" senttimetrin päässä"); 

/* Serial.print("Lähin objekti takana on %d senttimetrin päässä\n", distance2 ); 
  Serial.print(distance);
  Serial.print(" senttimetrin[cm]");
  Serial.println(" päässä."); 
  Serial.print("The closest object is "); 
  Serial.print(distance ); 
  Serial.print( "cm "); 
  Serial.println( "away.");
  */ 
  delay(100); 
}
