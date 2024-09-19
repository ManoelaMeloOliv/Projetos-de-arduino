int sensorPin = A0; 
int threshold = 500; 
int intensity = 0; 
int incomingByte = 0;

// === Pin Assignment ===//
int sVal_01 = 100;
char payload[150];

const int DO = 4; // Digital PIN 2 of Arduino
const int led_01 = 5;
const int led_02 = 6;
const int led_03 = 7;
const int led_04 = 8;
const int led_05 = 9;
const int led_06 = 10;
const int led_07 = 11;

int debugSwitch = false; // Switch for Debugging: true or false (ctrl+shift+M or
ctrl+shift+L)
int ledTest = true; // If true it will test the LEDs first before use (you can press reset
to check LEDs if running correctly

int sensorvalue = 0; // storage for recording sensor values

void setup() {
 Serial.begin(115200); // use the same baud-rate as the python side

 if (ledTest == true) {
 initTest(); // Initial testing for LED's
 }
}

void loop() {
 char data[2];
 if (debugSwitch == true) {
 debug();
 } else {
 //Serial.println("The debugging mode is set to false!");
 }

 if (Serial.available() > 0) {
 incomingByte = Serial.read();
 sensorvalue = incomingByte ;
 Serial.print("I received: ");
 Serial.println(incomingByte);
 }


 music();
}
void debug() {
 Serial.print("Sound Value: ");

 if (sensorvalue >= sVal_01) {
 Serial.print(sensorvalue);
 Serial.println(" - LED ON!");
 } else {
 Serial.println(sensorvalue);
 }
}

void initTest() {
 digitalWrite(led_05, HIGH);
 delay(100);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_06, HIGH);
 delay(100);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_07, HIGH);
 delay(100);
 digitalWrite(led_02, HIGH);
 delay(100);
 digitalWrite(led_01, HIGH);
 delay(200);
 digitalWrite(led_01, LOW);
 delay(50);
 digitalWrite(led_02, LOW);
 delay(50);
 digitalWrite(led_03, LOW);
 digitalWrite(led_07, LOW);
 delay(50);
 digitalWrite(led_04, LOW);
 digitalWrite(led_06, LOW);
 delay(50);
 digitalWrite(led_05, LOW);
}

void music() {
 int soundLevel = analogRead(sensorPin); // Lê o valor do sensor de som

 if (soundLevel > threshold) {
 intensity = map(soundLevel, threshold, 1023, 0, 255); // Mapeia o valor do sensor
para a faixa de intensidade dos LEDs
 } else {
 intensity = 0; // Se o som for menor que o limiar, desliga os LEDs
 }
 analogWrite(led_01, intensity);
 analogWrite(led_02, intensity);
 analogWrite(led_03, intensity);
 analogWrite(led_04, intensity);
 analogWrite(led_05, intensity);
 analogWrite(led_06, intensity);
 analogWrite(led_07, intensity);

 if (sensorvalue == 0) {
 digitalWrite(led_01, LOW);
 digitalWrite(led_02, LOW);
 digitalWrite(led_03, LOW);
 digitalWrite(led_04, LOW);
 digitalWrite(led_05, LOW);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 1) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, LOW);
 digitalWrite(led_03, LOW);
 digitalWrite(led_04, LOW);
 digitalWrite(led_05, LOW);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 2) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, LOW);
 digitalWrite(led_04, LOW);
 digitalWrite(led_05, LOW);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 3) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, LOW);
 digitalWrite(led_05, LOW);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 4) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_05, LOW);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 5) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_05, HIGH);
 digitalWrite(led_06, LOW);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 6) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_05, HIGH);
 digitalWrite(led_06, HIGH);
 digitalWrite(led_07, LOW);
 } else if (sensorvalue == 7) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_05, HIGH);
 digitalWrite(led_06, HIGH);
 digitalWrite(led_07, HIGH);
 } else if (sensorvalue == 8) {
 digitalWrite(led_01, HIGH);
 digitalWrite(led_02, HIGH);
 digitalWrite(led_03, HIGH);
 digitalWrite(led_04, HIGH);
 digitalWrite(led_05, HIGH);

 }
 }
