#ifndef GLOBALS_H

#define GLOBALS_H

//might do in with #define or const int idk
//might do in with #define
//might do in with #define
//might do in with #define

//pin mapping to MRAA numbers (https://iotdk.intel.com/docs/master/mraa/rasppi.html)
#define MRAA_1 1  //P1-11, GPIO(17)
#define MRAA_2 2  //P1-11, GPIO(17)
#define MRAA_3 3  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)
#define MRAA_  //P1-11, GPIO(17)

//sensor pins (sensors mapped to pin values)
const int ACCEL1_PIN = 11; //have classes for each sensor type (maybe class inheritence with an overall "sensor" class, and have constructor that takes in pin value when declared in "main"; i.e. ACCELEROMETER accel(ACCEL1_PIN)
const int ACCEL2_PIN = 12;

const int GYRO1_PIN = 12;
const int GYRO2_PIN = 12;

const int TEMP1_PIN = 12; //will be removed if barometer has temperature reading capabilities
const int TEMP2_PIN = 12;

const int BARO1_PIN = 12;
const int BARO2_PIN = 12;

const int CURRENT1_PIN = 12;
const int CURRENT2_PIN = 13;

const int MAG1_PIN = 12;
const int MAG2_PIN = 13;

//sensor data transmission rates
const int ACCEL_DATARATE_100_HZ = 100; //might have to have set data rates with constructor of sensor types or a "setdatarate" function within each the sensor classes
const int ACCEL_DATARATE_400_HZ = 400;

const int GYRO_DATARATE_100_HZ = 100;
const int GYRO_DATARATE_400_HZ = 400;

const int TEMP_DATARATE_100_HZ = 100;
const int TEMP_DATARATE_400_HZ = 400;

const int BARO_DATARATE_100_HZ = 100;
const int BARO_DATARATE_400_HZ = 400;

const int CURRENT_DATARATE_100_HZ = 100;
const int CURRENT_DATARATE_400_HZ = 400;

const int MAG_DATARATE_100_HZ = 100;
const int MAG_DATARATE_400_HZ = 400;

//arbritary mapping for function implementations in sensors.h and more
const int ACCEL = 1;
const int GYRO = 2;
const int TEMP = 3;
const int BARO = 4;
const int CURRENT = 5;
const int MAG = 6;

#endif