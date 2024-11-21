#include <Servo.h>

// Pin definitions
const int greenLEDPin = 8;     // Pin for Green LED
const int redLEDPin = 7;       // Pin for Red LED
const int blueLEDPin = 5;      // Pin for Blue LED
const int irSensorPin = 10;    // Digital pin for IR sensor

// Timing
const int waitTime = 2000;     // Wait time in milliseconds (2 seconds)

bool isSystemActive = false;   // Flag to track if system is running

void setup() {
  Serial.begin(9600);           // Initialize serial communication for debugging
  pinMode(greenLEDPin, OUTPUT); // Set green LED as output
  pinMode(redLEDPin, OUTPUT);   // Set red LED as output
  pinMode(blueLEDPin, OUTPUT);  // Set blue LED as output
  pinMode(irSensorPin, INPUT);  // Set IR sensor as input

  // Start with Green LED on (system ready)
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(redLEDPin, LOW);
  digitalWrite(blueLEDPin, LOW);
}

void loop() {
  // Read IR sensor
  int irValue = digitalRead(irSensorPin);
  Serial.println(irValue);        // Print IR value for debugging

  // Check if IR sensor detects object and system isn't already active
  if (irValue == LOW && !isSystemActive) {  // Most IR sensors output LOW when detecting
    isSystemActive = true;        // Set flag to prevent multiple activations

    // Start the sequence
    digitalWrite(greenLEDPin, LOW);   // Turn off Green LED
    digitalWrite(redLEDPin, HIGH);    // Turn on Red LED
    
    Serial.println("Object detected! Starting sequence."); // Print message
    
    delay(waitTime);  // Wait for specified time
    
    // Reset everything
    digitalWrite(greenLEDPin, HIGH);   // Turn on Green LED
    digitalWrite(redLEDPin, LOW);      // Turn off Red LED
    
    isSystemActive = false;            // Reset system active flag
  }
}
