#ifndef EEPROM_H
#define EEPROM_H

#include <avr/io.h>
#include <util/delay.h>

#define EEPROM_SIZE 1024

void eeprom_clear(void);
void eeprom_write_byte(uint8_t addr, uint8_t data);

#endif