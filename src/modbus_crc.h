#ifndef __MODBUS_CRC_H__
#define __MODBUS_CRC_H__

#include <Arduino.h>

extern const unsigned char CRCTableHigh[];
extern const unsigned char CRCTableLow[];

unsigned int ModbusCRC(unsigned char* ptr, unsigned char len);

#endif // __MODBUS_CRC_H__
