int led = D7;  // The on-board LED
int Moist = A1;
int analogMoist = 0;
int moistVolt = 0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(Moist, INPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  
  analogMoist = analogRead(Moist);
  moistVolt = (analogMoist*3300)/4096; //connect sensor to Analog 1
  Particle.publish("Moisture", (String)moistVolt, PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}