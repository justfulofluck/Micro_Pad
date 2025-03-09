#include <Keypad.h>

//Global variable
int counter = 0;

//function declaration
void Keypad_pad();
void encoder_one();
void encoder_two();

//Encoder 1 
#define CLK 5
#define DT 4
#define SW 3

int lastStateCLK = HIGH;
int currentStateCLK;

//Encoder 2
#define CLK_two 7
#define DT_two 6
#define SW_two 2

int lastStateCLK_two = HIGH;
int currentStateCLK_two;

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


void setup() {
  Serial.begin(115200); 
  // Encoder 1
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  //Encoder 2
  pinMode(CLK_two, INPUT);
  pinMode(DT_two, INPUT);
  pinMode(SW_two, INPUT_PULLUP);
}

void loop() {
  // Keypad handling
  Keypad_pad();
  encoder_one();
  encoder_two();
}

void Keypad_pad() {
  char customKey = customKeypad.getKey();
  if (customKey) {
    Serial.println(customKey);
  }
}

void encoder_one() {
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) != currentStateCLK) {
      counter++;
    } else {
      counter--;
    }
    Serial.println(counter);
  }
  lastStateCLK = currentStateCLK;
  delay(1000);
  if (digitalRead(SW) == LOW) {
    Serial.println("Encoder 1 Pressed!");
  } else {
    Serial.println("");
  }
}

void encoder_two() {
  currentStateCLK_two = digitalRead(CLK_two);
  if (currentStateCLK_two != lastStateCLK_two) {
    if (digitalRead(DT_two) != currentStateCLK_two) {
      counter++;
    } else {
      counter--;
    }
    Serial.println(counter);
  }
  lastStateCLK_two = currentStateCLK_two;
  delay(1000);
  if (digitalRead(SW_two) == LOW) {
    Serial.println("Encoder 2 Pressed!");
  } else {
    Serial.println("");
  }
}
