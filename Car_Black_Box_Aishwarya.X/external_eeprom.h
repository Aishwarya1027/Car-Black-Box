/* 
 * File:   external_eeprom.h
 * Author: haish
 *
 * Created on 30 April, 2026, 12:57 PM
 */



#ifndef EXTERNAL_EEPROM_H
#define	EXTERNAL_EEPROM_H

#define SLAVE_READ_E		0xA1
#define SLAVE_WRITE_E		0xA0

void write_external_eeprom(unsigned char address, unsigned char data);
unsigned char read_external_eeprom(unsigned char address);
#endif	/* EXTERNAL_EEPROM_H */