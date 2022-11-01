#define POT 2
#define LED_1 33
#define LED_2 32
#define LED_3 18
#define LED_4 19

float voltage;

void setup() {
  pinMode(POT, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(POT) * 3.3 / 4095;
  
  Serial.println("Voltage: " + String(voltage));

  if (voltage <= 1.0) {
    turnOnLed1();
  } else if (voltage > 1.0 && voltage <= 2.0) {
    turnOnLed2();
  } else if (voltage > 2.0 && voltage <= 3.0) {
    turnOnLed3();
  } else {
    turnOnLed4();
  }
}

void turnOnLed1() {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void turnOnLed2() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void turnOnLed3() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);
}

void turnOnLed4() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, HIGH);
}
