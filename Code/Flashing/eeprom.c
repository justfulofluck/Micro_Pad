#include "eeprom.h"

static void eeprom_busy_wait(void) {
    while (EECR & (1 << EERE));
}

void eeprom_write_byte(uint8_t addr, uint8_t data) {
    eeprom_busy_wait();

    EEAR = addr;
    EEDR = data;

    EECR |= (1 << EEMPE);
    EECR |= (1 << EEPE);
}

void eeprom_clear(void) {
    for (uint8_t i = 0; i < EEPROM_SIZE; i++) 
    {
        eeprom_write_byte(i, 0xFF);
        _delay_ms(10);
    }
}