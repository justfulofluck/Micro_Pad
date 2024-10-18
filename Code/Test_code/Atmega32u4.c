#include <Keyboard.h>

// Define pins for ATmega32U4
const uint8_t led = 13; // Pin for LED
const uint8_t button1 = 12; // Button 1
const uint8_t button2 = 11; // Button 2
const uint8_t button3 = 10; // Button 3
const uint8_t button4 = 9; // Changed from 8 to 9 for ATmega32U4 compatibility
const uint8_t button5 = 8; // Changed from 7 to 8 for ATmega32U4 compatibility
const uint8_t button6 = 7; // Changed from 6 to 7 for ATmega32U4 compatibility

// Define pins for rotary encoder
const uint8_t clock_pin = 2; // Clock pin for rotary encoder
const uint8_t data_pin = 3; // Data pin for rotary encoder

uint8_t lastClockState;
uint8_t volumeChange = 0;

// Button states
bool lastButtonState1 = LOW;
bool lastButtonState2 = LOW;
bool lastButtonState3 = LOW;
bool lastButtonState4 = LOW;
bool lastButtonState5 = LOW;
bool lastButtonState6 = LOW;

#define ON HIGH
#define OFF LOW

// Function Prototypes
void button_one();
void button_two();
void button_three();
void button_four();
void button_five();
void button_six();
void potmeter();
void pressKey(uint8_t key);

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
    pinMode(button5, INPUT);
    pinMode(button6, INPUT);
    
    // Rotary encoder
    pinMode(clock_pin, INPUT);
    pinMode(data_pin, INPUT);

    Keyboard.begin();
    lastClockState = digitalRead(clock_pin);
}

void loop() {
    potmeter();
    button_one();
    button_two();
    button_three();
    button_four();
    button_five();
    button_six();

    char input[100]{
    	mode
    }
}

// Functions

void potmeter() {
    uint8_t clockState = digitalRead(clock_pin);

    if (clockState != lastClockState) {
        if (digitalRead(data_pin) != clockState) {
            pressKey(KEY_VOLUME_UP);
        } else {
            pressKey(KEY_VOLUME_DOWN);
        }
        delay(100);
    }
    
    lastClockState = clockState;
}

void pressKey(uint8_t key) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(key);
    Keyboard.release(key);
    Keyboard.release(KEY_LEFT_CTRL);
    delay(100);
}

void button_one() {
    bool currentButtonState = digitalRead(button1);

    if (currentButtonState == HIGH && lastButtonState1 == LOW) {
        pressKey('c');
    }

    lastButtonState1 = currentButtonState;
}

void button_two() {
    bool currentButtonState = digitalRead(button2);

    if (currentButtonState == HIGH && lastButtonState2 == LOW) {
        pressKey('v');
    }

    lastButtonState2 = currentButtonState;
}

void button_three() {
    bool currentButtonState = digitalRead(button3);

    if (currentButtonState == HIGH && lastButtonState3 == LOW) {
        pressKey('x');
    }

    lastButtonState3 = currentButtonState;
}

void button_four() {
    bool currentButtonState = digitalRead(button4);

    if (currentButtonState == HIGH && lastButtonState4 == LOW) {
        pressKey('v');
    }

    lastButtonState4 = currentButtonState;
}

void button_five() {
    bool currentButtonState = digitalRead(button5);

    if (currentButtonState == HIGH && lastButtonState5 == LOW) {
        pressKey('v');
   }

   lastButtonState5 = currentButtonState;
}

void button_six() {
   bool currentButtonState = digitalRead(button6);

   if (currentButtonState == HIGH && lastButtonState6 == LOW) {
       pressKey('v');
   }

   lastButtonState6 = currentButtonState;
}