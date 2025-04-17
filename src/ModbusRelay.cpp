
#include "ModbusRelay.h"
#include <Arduino.h>
#include "modbus_crc.h"

ModbusRelay::ModbusRelay(uint8_t rxPin, uint8_t txPin, uint32_t baudRate, uint8_t deviceId, HardwareSerial* serial)
    : _rxPin(rxPin), _txPin(txPin), _baudrate(baudRate), _deviceId(deviceId), _serial1(serial) {
}


 
void ModbusRelay::begin(){

    _serial1->begin(_baudrate, SERIAL_8N1, _rxPin, _txPin);

}


void ModbusRelay::sendCommand(uint16_t address, uint16_t value) {
 
uint8_t frame[8];

frame[0] = _deviceId; // Slave address
frame[1] = 0x05; // Function code (Write Single Coil)
frame[2] = highByte(address); 
frame[3] = lowByte(address); 
frame[4] = highByte(value); 
frame[5] = lowByte(value); 


unsigned int crc = ModbusCRC(frame, 6);

frame[6] = lowByte(crc);
frame[7] = highByte(crc);

_serial1->write(frame,8);
_serial1->flush();


}

}


void ModbusRelay::sendCommand(uint16_t address, uint16_t value) {
 
uint8_t frame[8];

frame[0] = _deviceId; // Slave address
frame[1] = 0x05; // Function code (Write Single Coil)
frame[2] = highByte(address); 
frame[3] = lowByte(address); 
frame[4] = highByte(value); 
frame[5] = lowByte(value); 


unsigned int crc = ModbusCRC(frame, 6);

frame[6] = lowByte(crc);
frame[7] = highByte(crc);

_serial1->write(frame,8);
_serial1->flush();


}
