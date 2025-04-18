#include <ModbusRelay.h>

// Define pins for RS485 communication
#define RX_PIN 18  // ESP32 RX pin for RS485
#define TX_PIN 17  // ESP32 TX pin for RS485

//Create a instance of class ModbusRelay and set your budrate and id 
ModbusRelay relay(RX_PIN, TX_PIN,9600,1);

void setup() {
 
  Serial.begin(115200);
  Serial.println("ModbusRelay Library Test");
  

  relay.begin(); 

  //Set the new address for you relay module 
  relay.setAddress(2);
  Serial.println("Setup complete");
}

void loop() {


  

}
