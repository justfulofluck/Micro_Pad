#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Keyboard.h>

// Pin definitions
extern const uint8_t led;
extern const uint8_t button1;
extern const uint8_t button2;
extern const uint8_t button3;
extern const uint8_t button4;
extern const uint8_t button5;
extern const uint8_t button6;

extern const uint8_t clock_pin;
extern const uint8_t data_pin;

// Function prototypes
void setup_controller(void);
void loop_controller(void);
void potmeter(void);
void pressKey(uint8_t key);
void button_one(void);
void button_two(void);
void button_three(void);
void button_four(void);
void button_five(void);
void button_six(void);

#endif // CONTROLLER_H