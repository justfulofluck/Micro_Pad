#include <Keypad.h>

// Encoder pins
#define ENCODER_CLK 2
#define ENCODER_DT 3
#define ENCODER_BTN 4

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char hexKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  // Connect to row pinouts
byte colPins[COLS] = {5, 4, 3, 2};  // Connect to column pinouts

Keypad customKeypad = Keypad(makeKeymap(hexKeys), rowPins, colPins, ROWS, COLS);

// Encoder variables
int lastClk = HIGH;
bool btnPressed = false;

void setup() {
  Serial.begin(115200);  // Fixed: Only one serial.begin needed
  pinMode(ENCODER_BTN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_CLK, INPUT);
}

void loop() {
  // Keypad handling
  char customKey = customKeypad.getKey();
  if (customKey) {
    Serial.println(customKey);
  }

  // Encoder handling
  encoder();
  encoder_button();
}

void encoder() {
  int newClk = digitalRead(ENCODER_CLK);
  if (newClk != lastClk) {
    // Debounce delay
    delay(1);
    int dtValue = digitalRead(ENCODER_DT);
    
    if (newClk == LOW) {
      if (dtValue == HIGH) {
        Serial.println("Rotated clockwise");
      } else {
        Serial.println("Rotated counterclockwise");
      }
    }
    lastClk = newClk;
  }
}

void encoder_button() {
  if (digitalRead(ENCODER_BTN) == LOW) {
    if (!btnPressed) {
      btnPressed = true;
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Encoder button pressed!");
      delay(50);  // Debounce delay
    }
  } else {
    if (btnPressed) {
      btnPressed = false;
      digitalWrite(LED_BUILTIN, LOW);
      delay(50);  // Debounce delay
    }
  }
}
