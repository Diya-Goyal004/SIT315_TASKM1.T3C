// Define the pins for PIR sensors and LEDs
const int pirPin1 = 2; // PIR sensor 1 connected to digital pin 2
const int pirPin2 = 3; // PIR sensor 2 connected to digital pin 3
const int ledPin1 = 13; // LED blue connected to digital pin 13
const int ledPin2 = 12; // LED green connected to digital pin 12

// Variables to store the state of PIR sensors
volatile int pirState1 = LOW;
volatile int pirState2 = LOW;

void setup() {
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Attach interrupts to the PIR sensor pins
  attachInterrupt(digitalPinToInterrupt(pirPin1), pirEvent1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pirPin2), pirEvent2, CHANGE);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Nothing to do here as we handle PIR events through interrupts
}

// Interrupt service routine for PIR sensor 1
void pirEvent1() {
  pirState1 = digitalRead(pirPin1);
  if (pirState1 == HIGH) {
    Serial.println("PIR sensor 1 triggered");
    digitalWrite(ledPin1, HIGH); // Turn on LED 1
  } else {
    Serial.println("PIR sensor 1 released");
    digitalWrite(ledPin1, LOW); // Turn off LED 1
  }
}

// Interrupt service routine for PIR sensor 2
void pirEvent2() {
  pirState2 = digitalRead(pirPin2);
  if (pirState2 == HIGH) {
    Serial.println("PIR sensor 2 triggered");
    digitalWrite(ledPin2, HIGH); // Turn on LED 2
  } else {
    Serial.println("PIR sensor 2 released");
    digitalWrite(ledPin2, LOW); // Turn off LED 2
  }
}
