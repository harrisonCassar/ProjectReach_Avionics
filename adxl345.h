#ifndef ADXL345_H

#define ADXL_345_H

#include "sensors.h"

//address and ID
#define ADXL345_I2C_ADDR 0x1D //or 0x53 for address IF ALT ADDRESS pin (Pin 12) is grounded
#define ADXL345_ID 0x00 //device ID

//const int ADXL345_I2C_WRITE = 0x3A; //or 0xA6
//const int ADXL345_I2C_READ = 0x3B; //or 0xA7

//control registers
#define ADXL345_OFSX 0x1E
#define ADXL345_OFSY 0x1F
#define ADXL345_OFSZ 0x20
#define ADXL345_TAP_THRESH 0x1D
#define ADXL345_TAP_DUR 0x21
#define ADXL345_TAP_LATENCY 0x22
#define ADXL345_ACT_THRESH 0x24
#define ADXL345_INACT_THRESH 0x25
#define ADXL345_INACT_TIME 0x26
#define ADXL345_INACT_ACT_CTL 0x27
#define ADXL345_FALL_THRESH 0x28
#define ADXL345_FALL_TIME 0x29
#define ADXL345_TAP_AXES 0x2A
#define ADXL345_ACT_TAP_STATUS 0x2B

//interrupt registers
#define ADXL345_INT_ENABLE 0x2E
#define ADXL345_INT_MAP 0x2F
#define ADXL345_INT_SOURCE 0x30

//data registers (read only) (eight bits each)
#define ADXL345_XOUT_L 0x32
#define ADXL345_XOUT_H 0x33
#define ADXL345_YOUT_L 0x34
#define ADXL345_YOUT_H 0x35
#define ADXL345_ZOUT_L 0x36
#define ADXL345_ZOUT_H 0x37
#define DATA_REG_SIZE 6

//data and power management
#define ADXL345_BW_RATE 0x2C
#define ADXL345_POWER_CTL 0x2D
#define ADXL345_DATA_FORMAT 0x31 //this controls the format of the data
#define ADXL345_FIFO_CTL 0x38
#define ADXL345_FIFO_STATUS 0x39

//useful values
#define ADXL345_POWER_ON 0x08
#define ADXL345_AUTO_SLP 0x30
#define ADXL345_STANDBY 0x00

//scales and resolution
#define ADXL345_FULL_RES 0x08
#define ADXL345_10BIT 0x00
#define ADXL345_2G 0x00
#define ADXL345_4G 0x01
#define ADXL345_8G 0x02
#define ADXL345_16G 0x03

//accel
class ADXL345: public Sensor
{
public:
	ADXL345(int busID):Sensor(busID);

	virtual bool calibrate() {/*...*/}
	//zeros sensor to current reading (different sensors will have slightly different implementations)
	//returns true if successfully calibrated; false otherwise
	//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)
	//supports 
private:
	float m_accel[3];


}

#endif