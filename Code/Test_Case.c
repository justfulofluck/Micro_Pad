// For library and functionality testing

// test

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //unsigned bit_state_one = 0x00000100;
    //unsigned bit_state_two = 0x00100010;

    unsigned added_state = 0x00000100;
    added_state |= (1<<5);
    unsigned opp_one = added_state;
    printf("%x\n", opp_one);
    unsigned bitter_state = 0x00100010;
    bitter_state &= ~(1<<5);
    unsigned opp_two = bitter_state;
    printf("%x\n", opp_two);
    int res_state = opp_one & opp_two;

    printf("%x\n", res_state);

    return 0;
}

// 00000000
// 00100000
// 0020,0000
//    2,0=20 

//base code for keypad:
#include <Keyboard.h> // Include Keyboard library

// Define pin for the button
const int buttonPin = 2;
bool lastButtonState = LOW; // Previous state of the button

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(buttonPin, INPUT); // Set button pin as input
  Keyboard.begin(); // Initialize Keyboard library
}

void loop() {
  // Read the current state of the button
  bool currentButtonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    Serial.println("Button pressed, sending Ctrl+C");
    
    // Simulate Ctrl+C
    Keyboard.press(KEY_LEFT_CTRL); // Press Ctrl
    Keyboard.press('c');             // Press 'C'
    Keyboard.release('c');           // Release 'C'
    Keyboard.release(KEY_LEFT_CTRL); // Release Ctrl
    
    delay(100); // Debounce delay
  }

  lastButtonState = currentButtonState; // Update last state
}

// Base code for Roter
#include <Keyboard.h> // Include Keyboard library

// Define pins for rotary encoder
const int clkPin = 2; // Clock pin
const int dtPin = 3;  // Data pin

int lastClkState;
int volumeChange = 0;

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  
  Keyboard.begin(); // Initialize Keyboard library
  lastClkState = digitalRead(clkPin); // Read initial state of clock pin
}

void loop() {
  int clkState = digitalRead(clkPin);
  
  // Check if there is a change in state
  if (clkState != lastClkState) {
    // If clock state has changed, check direction
    if (digitalRead(dtPin) != clkState) {
      // Clockwise rotation - increase volume
      Keyboard.press(KEY_LEFT_CTRL); // Press Ctrl
      Keyboard.press(KEY_VOLUME_UP);  // Press Volume Up key
      Keyboard.release(KEY_VOLUME_UP); // Release Volume Up key
      Keyboard.release(KEY_LEFT_CTRL); // Release Ctrl
      Serial.println("Volume Up");
    } else {
      // Counter-clockwise rotation - decrease volume
      Keyboard.press(KEY_LEFT_CTRL);   // Press Ctrl
      Keyboard.press(KEY_VOLUME_DOWN);  // Press Volume Down key
      Keyboard.release(KEY_VOLUME_DOWN); // Release Volume Down key
      Keyboard.release(KEY_LEFT_CTRL);   // Release Ctrl
      Serial.println("Volume Down");
    }
    
    delay(100); // Debounce delay
  }
  
  lastClkState = clkState; // Update last state
}


// mode select
#include <stdio.h>
#include <string.h>

void execom() {
    printf("an nother command");
}

int main() {
    char input[100];
    printf("commad here \n");
    scanf("%s", input);

    if (strcmp(input, "set") ==0) {
        execom();
    } else {
        printf("noe known error", input);
    }

    return 0;
}
