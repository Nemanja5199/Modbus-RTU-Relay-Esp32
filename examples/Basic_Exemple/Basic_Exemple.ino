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
  Serial.println("Setup complete");
}

void loop() {

Serial.println("Turning ON relay 1...");
  relay.turnOn(1);
  delay(2000);
  
  Serial.println("Turning OFF relay 1...");
  relay.turnOff(1);
  delay(2000);
  
  Serial.println("Toggling relay 2...");
  relay.toggle(2);
  delay(2000);
  
  // Test controlling all relays
  Serial.println("Turning ALL relays ON...");
  relay.allOn();
  delay(3000);
  
  Serial.println("Turning ALL relays OFF...");
  relay.allOff();
  delay(3000);
  
  Serial.println("Toggling ALL relays...");
  relay.allToggle();
  delay(3000);
  
  

}
