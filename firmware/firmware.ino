uint8_t buf[8] = { 0 }; //Keyboard report buffer

#define PIN_W 9 // Pin for w

#define PIN_A 10 // Pin for a

#define PIN_S 6 // Pin for s

#define PIN_D 7 // Pin for d

void setup() {

  Serial.begin(9600); // Setup Serial communication

  //Set pinmode of Input pins

  pinMode(PIN_W, INPUT);

  pinMode(PIN_A, INPUT);

  pinMode(PIN_S, INPUT);

  pinMode(PIN_D, INPUT);

}

void loop() {

  if (digitalRead(PIN_A) == HIGH) {

    Serial.println("button1");
    delay(100);
  }

  else if (digitalRead(PIN_W) == HIGH) {

    Serial.println("button2");
    delay(100);
  }

delay(200);
}
