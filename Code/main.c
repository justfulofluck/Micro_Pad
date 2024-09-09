#include <Keypad.h>
#include <Keyboard.h> // Corrected spelling from Keybord to Keyboard

const uint8_t ROWS = 2;
const uint8_t COLS = 3;

// Use characters for keys instead of integers
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'}
};

uint8_t rowPins[ROWS] = {9, 8};
uint8_t colPins[COLS] = {7, 6, 5};

// Corrected the function name from makesKeymap to makeKeymap
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() 
{
  Keyboard.begin(); // Corrected 'keyboard' to 'Keyboard'
}

void loop() 
{
  char key = keypad.getKey(); // Corrected 'Keypad.getKey()' to 'keypad.getKey()'

  if (key) { // Corrected 'Key' to 'key'
    switch (key) { // Corrected 'Key' to 'key'

      // Opens Windows Explorer
      case '1':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('e'); 
        Keyboard.releaseAll();
        break;
      
      // Opens Start
      case '2':
        Keyboard.press(KEY_LEFT_CTRL); // Corrected 'KEY_LEFT_CRTL' to 'KEY_LEFT_CTRL'
        Keyboard.press('s');
        Keyboard.releaseAll();
        break;

      // Opens File Manager
      case '3':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('f');
        Keyboard.releaseAll();
        break;
      
      // Opens Task Manager
      case '4':
        Keyboard.press(KEY_LEFT_CTRL); // Corrected 'LEY_LEFT_CTRL' to 'KEY_LEFT_CTRL'
        Keyboard.press(KEY_ESC); // Changed 'ESC' to 'KEY_ESC'
        Keyboard.releaseAll();
        break;

      // Decrease brightness
      case '5':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_F1); 
        Keyboard.releaseAll();
        break;
      
      // Increase brightness
      case '6':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_F2); 
        Keyboard.releaseAll();
        break;
    }
  }
}
