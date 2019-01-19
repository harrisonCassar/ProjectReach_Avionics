#ifndef DATAPACKET_H

#define DATAPACKET_H

#include "sensors.h" //include for sensors polling and status functionality

//FOR SD CARD OPERATIONS; LEARNING HOW THEY WORK
#include <SPI.h>
#include <SD.h>

struct datapacket {
  unsigned long timestamp;
  float accel_x;
  float accel_y;
  float accel_z;
  float gyro_x;
  float gyro_y;
  float gyro_z;
  float mag_x;
  float mag_y;
  float mag_z;
  float mag_heading; 
  float temp_tempC;
  float baro_pressure; // in mmHg
  float baro_altitude; // in meters
};

//can't do reference in C, so change to pointers
//can't do reference in C, so change to pointers
//can't do reference in C, so change to pointers

bool init(&datapacket dp); {/*...*/}
//initializes data packet's values to 0..?

bool print(const &datapacket dp) {/*...*/}
//prints all of datapacket struct's data members to output screen



bool construct(&datapacket dp) {/*...*/}
//passing in data packet to construct
//call "preprocess"ing function on all active sensors, and assign the return values to the data packet's members

//accessor for every individual value in datapacket

private:
  data

};

dataPacket hello;

#endif