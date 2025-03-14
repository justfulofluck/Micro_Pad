#include "controller.h"

// Pin definitions
const uint8_t led = 13;
const uint8_t button1 = 12; // Use these as the multiple touch
const uint8_t button2 = 11;
const uint8_t button3 = 10;
const uint8_t button4 = 8;
const uint8_t button5 = 7;
const uint8_t button6 = 6;

// Define pins for rotary encoder
const uint8_t clock_pin = 2;
const uint8_t data_pin = 3;

const uint8_t clock_pin_two = 2; // need to reconfigure these pin.
const uint8_t data_pin_two = 3; // need to reconfigure these pin.

uint8_t lastClockState;
bool lastButtonState1 = LOW;
bool lastButtonState2 = LOW;
bool lastButtonState3 = LOW;
bool lastButtonState4 = LOW;
bool lastButtonState5 = LOW;
bool lastButtonState6 = LOW;

void setup_controller() {
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

    // Rotary 2 encoder
    pinMode(clock_pin_two, INPUT);
    pinMode(data_pin_two, INPUT);

    Keyboard.begin();
    lastClockState = digitalRead(clock_pin);
}

void loop_controller() {
    potmeter();
    button_one();
    button_two();
    button_three();
    button_four();
    button_five();
    button_six();
}
// rotar 1
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
// rotar 2 
// pin is not define in the program. (kind of dismantel program section)



// button 1
void pressKey(uint8_t key) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(key);
    Keyboard.release(key);
    Keyboard.release(KEY_LEFT_CTRL);
    delay(100);
}
// button 2
void button_one() {
    bool currentButtonState = digitalRead(button1);

    if (currentButtonState == HIGH && lastButtonState1 == LOW) {
        pressKey('c');
    }

    lastButtonState1 = currentButtonState;
}
// button 2
void button_two() {
    bool currentButtonState = digitalRead(button2);

    if (currentButtonState == HIGH && lastButtonState2 == LOW) {
        pressKey('v');
    }

    lastButtonState2 = currentButtonState;
}
// button 3
void button_three() {
    bool currentButtonState = digitalRead(button3);

    if (currentButtonState == HIGH && lastButtonState3 == LOW) {
        pressKey('x');
    }

    lastButtonState3 = currentButtonState;
}
// button 4
void button_four() {
    bool currentButtonState = digitalRead(button4);

    if (currentButtonState == HIGH && lastButtonState4 == LOW) {
        pressKey('v');
    }

    lastButtonState4 = currentButtonState;
}
// button 5
void button_five() {
    bool currentButtonState = digitalRead(button5);

    if (currentButtonState == HIGH && lastButtonState5 == LOW) {
        pressKey('v');
    }

    lastButtonState5 = currentButtonState;
}
// button 6
void button_six() {
    bool currentButtonState = digitalRead(button6);

    if (currentButtonState == HIGH && lastButtonState6 == LOW) {
        pressKey('v');
    }

    lastButtonState6 = currentButtonState;
}