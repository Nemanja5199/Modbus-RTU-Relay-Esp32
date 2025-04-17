#ifndef MODBUS_RELAY_H
#define MODBUS_RELAY_H

#include <Arduino.h>
#include "modbus_crc.h"

class ModbusRelay {
private:
    HardwareSerial* _serial1;
    uint8_t _rxPin;
    uint8_t _txPin;
    uint8_t _deviceId;
    uint32_t _baudRate;

    void sendCommand(uint16_t address, uint16_t value);
    
public:
    static const uint16_t RELAY_ON = 0xFF00;
    static const uint16_t RELAY_OFF = 0x0000;
    static const uint16_t RELAY_TOGGLE = 0x5500;
    static const uint16_t ALL_RELAYS_ADDR = 0x00FF;

    ModbusRelay(uint8_t rxPin, uint8_t txPin, uint32_t baudRate = 9600, uint8_t deviceId = 1, HardwareSerial* serial = &Serial1);
    
    void begin();
    
    void turnOn(uint8_t relayNum);
    void turnOff(uint8_t relayNum);
    void toggle(uint8_t relayNum);
    void allOn();
    void allOff();
    void allToggle();
};

#endif // MODBUS_RELAY_H
