const uint8_t led = 13;
const uint8_t button1 = 12;
const uint8_t button2 = 11;
const uint8_t button3 = 10;
const uint8_t button4 = 8;
const uint8_t button5 = 7;
const uint8_t button6 = 6;

const uint8_t potPin = A0;
const uint8_t ledpot = 9;

#define ON HIGH
#define OFF LOW
  
//Funciton Prototype
 void button_one();
 void button_two();
 void button_three();
 void button_four();
 void button_five();
 void button_six();
 void potmeter();

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
  pinMode(ledpot, OUTPUT);
}

void loop(){
  button_one();
  button_two();
  button_three();
  button_four();
  button_five();
  button_six();
  potmeter();
}

// functions

void potmeter() {
  uint8_t potValue = analogRead(potPin);
  uint8_t brightness = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(ledpot, brightness);
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.print(brightness);
  
  delay(100);
}


void button_one(){
  uint8_t buttonState = digitalRead(button1);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}

void button_two(){
  uint8_t buttonState = digitalRead(button2);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}

void button_three(){
  uint8_t buttonState = digitalRead(button3);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}

void button_four(){
  uint8_t buttonState = digitalRead(button4);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}

void button_five(){
  uint8_t buttonState = digitalRead(button5);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}

void button_six(){
  uint8_t buttonState = digitalRead(button6);
  
  if (buttonState == ON) {
    digitalWrite(led, ON);
  } else {
    digitalWrite(led, OFF);
  }
}
