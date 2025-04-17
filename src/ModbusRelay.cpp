
#include "ModbusRelay.h"

ModbusRelay::ModbusRelay(uint8_t rxPin, uint8_t txPin, uint32_t baudRate, uint8_t deviceId, HardwareSerial* serial)
    : _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate), _deviceId(deviceId), _serial1(serial) {
}


 
void ModbusRelay::begin(){

    _serial1->begin(_baudRate, SERIAL_8N1, _rxPin, _txPin);

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




void ModbusRelay :: turnOn(uint8_t relayNum) {

uint16_t address = relayNum - 1 ;

sendCommand(address , RELAY_ON);


}




void ModbusRelay :: turnOff(uint8_t relayNum){


uint16_t address = relayNum - 1 ;

sendCommand(address , RELAY_OFF);


}


void ModbusRelay :: toggle(uint8_t relayNum){

uint16_t address = relayNum - 1 ;

sendCommand(address ,  RELAY_TOGGLE);

}


void ModbusRelay :: allOn(){

    sendCommand(ALL_RELAYS_ADDR, RELAY_ON);
}
 

void ModbusRelay :: allOff(){

    sendCommand(ALL_RELAYS_ADDR, RELAY_OFF);

}



void ModbusRelay :: allToggle(){

    sendCommand(ALL_RELAYS_ADDR, RELAY_TOGGLE);
}



