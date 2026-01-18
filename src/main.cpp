#include <Arduino.h>
#include <SPI.h>
#define _SS 0


void setup() {
  pinMode( _SS, OUTPUT); //Set D0_Pin , OUTPUT (Slave Select)
  digitalWrite(_SS,HIGH); 
  SPI.begin(); //Initialize SPI library
  SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0)); //Set SPI parameters
  digitalPinToPort(_SS)->OUTCLR.reg = digitalPinToBitMask(_SS); //SS LOW
  SPI.transfer(0x40); //Device Opcode (0100 A2 A1 A0 R/W)
  SPI.transfer(0x00); //IODIRA Register Address
  SPI.transfer(0x00); //Set IODIRA Register Output
  SPI.transfer(0x00); //Set IODIRA Register Output
  digitalPinToPort(_SS)->OUTSET.reg = digitalPinToBitMask(_SS); //SS HIGH
}

void loop() {
  digitalPinToPort(_SS)->OUTCLR.reg = digitalPinToBitMask(_SS); //SS LOW
  SPI.transfer(0x40); //Device Opcode (0100 A2 A1 A0 R/W)
  SPI.transfer(0x12); //GPIOA Register Address
  SPI.transfer(0x01); //Set GPIOA Register - Set Pin 0 HIGH
  digitalPinToPort(_SS)->OUTSET.reg = digitalPinToBitMask(_SS); //SS HIGH
  delay(500);
  digitalPinToPort(_SS)->OUTCLR.reg = digitalPinToBitMask(_SS); //SS LOW
  SPI.transfer(0x40); //Device Opcode (0100 A2 A1 A0 R/W)
  SPI.transfer(0x12); //GPIOA Register Address
  SPI.transfer(0x80); //OUTPUT DATA (0x80)
  digitalPinToPort(_SS)->OUTSET.reg = digitalPinToBitMask(_SS); //SS HIGH
  delay(500);
}