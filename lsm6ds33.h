//another found GPIO interface library for the raspberry pi: http://wiringpi.com/reference/i2c-library/
//data sheet and other info about sensor can be referenced here: https://www.st.com/resource/en/datasheet/lsm6ds33.pdf

#ifndef LSM6DS33_H

#define LSM6DS33_H

#include <iostream>
#include <cstdlib>
#include "sensors.h"
#include "globals.h"

//buffer size for writing values to registers
#define BUFFER_SIZE 14
#define DATA_REG_SIZE 14

//address
#define LSM6DS33_I2C_ADDR 0xD6 //7-bit address form; default in 'write' state; implies connection to supply voltage; 0xD4 for connection to ground; general form: 110101xb

/*
The Slave ADdress (SAD) associated to the LSM6DS33 is 110101xb. The SDO/SA0 pin
can be used to modify the less significant bit of the device address. If the SDO/SA0 pin is
connected to the supply voltage, LSb is ‘1’ (address 1101011b); else if the SDO/SA0 pin is
connected to ground, the LSb value is ‘0’ (address 1101010b). This solution permits to
connect and address two different inertial modules to the same I2C bus.

LSB is 1 (8th bit in address) for read
LSB is 0 (8th bit in address) for write
*/

//registers
#define LSM6DS33_FIFO_CTRL1			0x06
#define LSM6DS33_FIFO_CTRL2			0x07
#define LSM6DS33_FIFO_CTRL3			0x08
#define LSM6DS33_FIFO_CTRL4			0x09
#define LSM6DS33_FIFO_CTRL5			0x0A
#define LSM6DS33_ORIENT_CFG_G		0x0B

#define LSM6DS33_INT1_CTRL			0x0D
#define LSM6DS33_INT2_CTRL			0x0E
#define LSM6DS33_WHO_AM_I			0x0F
#define LSM6DS33_CTRL1_XL			0x10
#define LSM6DS33_CTRL2_G			0x11
#define LSM6DS33_CTRL3_C			0x12
#define LSM6DS33_CTRL4_C			0x13
#define LSM6DS33_CTRL5_C			0x14
#define LSM6DS33_CTRL6_C			0x15
#define LSM6DS33_CTRL7_G			0x16

#define LSM6DS33_CTRL8_XL          	0x17
#define LSM6DS33_CTRL9_XL          	0x18
#define LSM6DS33_CTRL10_C          	0x19

#define LSM6DS33_WAKE_UP_SRC       	0x1B
#define LSM6DS33_TAP_SRC           	0x1C
#define LSM6DS33_D6D_SRC           	0x1D
#define LSM6DS33_STATUS_REG       	0x1E

#define LSM6DS33_OUT_TEMP_L        	0x20 //lower 8-bits of overall 16-bit word in two's complement (applies to all data output registers)
#define LSM6DS33_OUT_TEMP_H       	0x21
#define LSM6DS33_OUTX_L_G          	0x22
#define LSM6DS33_OUTX_H_G          	0x23
#define LSM6DS33_OUTY_L_G          	0x24
#define LSM6DS33_OUTY_H_G          	0x25
#define LSM6DS33_OUTZ_L_G          	0x26
#define LSM6DS33_OUTZ_H_G          	0x27
#define LSM6DS33_OUTX_L_XL         	0x28
#define LSM6DS33_OUTX_H_XL         	0x29
#define LSM6DS33_OUTY_L_XL         	0x2A
#define LSM6DS33_OUTY_H_XL         	0x2B
#define LSM6DS33_OUTZ_L_XL         	0x2C
#define LSM6DS33_OUTZ_H_XL         	0x2D
#define LSM6DS33_FIFO_STATUS1      	0x3A
#define LSM6DS33_FIFO_STATUS2      	0x3B
#define LSM6DS33_FIFO_STATUS3      	0x3C
#define LSM6DS33_FIFO_STATUS4      	0x3D
#define LSM6DS33_FIFO_DATA_OUT_L   	0x3E
#define LSM6DS33_FIFO_DATA_OUT_H   	0x3F
#define LSM6DS33_TIMESTAMP0_REG    	0x40
#define LSM6DS33_TIMESTAMP1_REG    	0x41
#define LSM6DS33_TIMESTAMP2_REG    	0x42

#define LSM6DS33_STEP_TIMESTAMP_L  	0x49
#define LSM6DS33_STEP_TIMESTAMP_H  	0x4A
#define LSM6DS33_STEP_COUNTER_H    	0x4C

#define LSM6DS33_FUNC_SRC          	0x53

#define LSM6DS33_TAP_CFG           	0x58
#define LSM6DS33_TAP_THS_6D        	0x59
#define LSM6DS33_INT_DUR2          	0x5A
#define LSM6DS33_WAKE_UP_THS       	0x5B
#define LSM6DS33_WAKE_UP_DUR       	0x5C
#define LSM6DS33_FREE_FALL         	0x5D
#define LSM6DS33_MD1_CFG           	0x5E
#define LSM6DS33_MD2_CFG           	0x5F

//useful values
#define LSM6DS33_ACCEL_POWER_ON		0xA0 //this is at 6.6kHz (high performance)
#define LSM6DS33_GYRO_POWER_ON		0x80 //this is at 1.66kHz (high performance)
#define LSM6DS33_POWER_OFF 			0x00

class LSM6DS33: public Sensor
{
public:
	LSM6DS33(int busID, int instance):Sensor(busID,instance), m_i2c(busID)
	{
		//set I2C address
		if (m_i2c.address(LSM6DS33_I2C_ADDR) != mraa::SUCCESS)
		{
			std::cerr << "Unable to set I2C address." << endl;
			exit(ERROR_ADDR);
		}

		//send "Power On" command for accelerometer
		//change from default accelerometer full-scale selection to +-16g instead of +-2g
		m_buffer[0] = LSM6DS33_CTRL1_XL;
		m_buffer[1] = LSM6DS33_ACCEL_POWER_ON | 0x4;

		if (m_i2c.write(m_buffer, 2) != mraa::SUCCESS)
		{
			std::cerr << "Unable to write ACCEL_POWER_ON to LSM6DS33." << endl;
			exit(ERROR_POWER);
		}

		//send "Power On" command for gyroscope
		//change from default gyroscope full-scale selection to +-, 'OR' value here with LSM6DS33_GYRO_POWER_ON
		m_buffer[0] = LSM6DS33_CTRL2_G;
		m_buffer[1] = LSM6DS33_GYRO_POWER_ON; //MIGHT WANT TO CHANGE THIS 

		if (m_i2c.write(m_buffer, 2) != mraa::SUCCESS)
		{
			std::cerr << "Unable to write GYRO_POWER_ON to LSM6DS33." << endl;
			exit(ERROR_POWER);
		}

		/*//run calibration of sensor
		if (calibrate() == false)
		{
			std::cerr << "Unsuccessful LSM6DS33 calibration." << endl;
			exit(ERROR_CALIB); //might not be wanted, as calibration could be potentially not required
		}*/

		//run first update of sensor
		if (poll() == false)
		{
			std::cerr << "Unable to initial poll LSM6DS33." << endl;
			exit(ERROR_POLL);
		}

		//set offsets
		m_temp_offset = 1;
		m_accel_offsets[0] = 1; //THESE VALUES HAVE NOT BEEN TESTED FOR YET
    	m_accel_offsets[1] = 1;
    	m_accel_offsets[2] = 1;
    	m_gyro_offsets[0] = 1; //THESE VALUES HAVE NOT BEEN TESTED FOR YET
    	m_gyro_offsets[1] = 1;
    	m_gyro_offsets[2] = 1;
	}

	virtual bool calibrate() {/*...*/}
	//zeros sensor to current reading (different sensors will have slightly different implementations)
	//returns true if successfully calibrated; false otherwise
	//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)

	virtual bool poll()
	{
		/*
		NOTE: STATUS_REG can be used to check if data is available for temp/gyro/accel
		Look into this, as could use as a way to see if read-in data is just old data that was never updated
		*/

		//set I2C address
		if (m_i2c.address(LSM6DS33_I2C_ADDR) != mraa::SUCCESS)
		{
			std::cerr << "Unable to set I2C address." << endl;
			exit(ERROR_ADDR);
		}

		//read temp,x,y,z (14 bytes) into buffer
		if (m_i2c.readBytesReg(LSM6DS33_OUT_TEMP_L, m_buffer, DATA_REG_SIZE) == -1)
		{
			std::cerr << "Unable to read data bytes starting from LSM6DS33_OUT_TEMP_L." << endl;
			exit(ERROR_POLL);
		}

		//record rawacceleration values using data reads for x,y,z respectively
		//DATAx0 is the least significant byte, and DATAx1 is the most significant byte
		m_temp_raw = ((m_buffer[1] << 8) | m_buffer[0]);

    	m_accel_raw[0] = ((m_buffer[3] << 8 ) | m_buffer[2]);
    	m_accel_raw[1] = ((m_buffer[5] << 8 ) | m_buffer[4]);
    	m_accel_raw[2] = ((m_buffer[7] << 8 ) | m_buffer[6]);

    	m_gyro_raw[0] = ((m_buffer[9] << 8 ) | m_buffer[8]);
    	m_gyro_raw[1] = ((m_buffer[11] << 8 ) | m_buffer[10]);
    	m_gyro_raw[2] = ((m_buffer[13] << 8 ) | m_buffer[12]);

    	return true;
	}

	//virtual bool longPoll() { return false; /*dummy*/}
	//call poll() over a longer period of time, averaging out the values (maybe allow time input functionality, or just do poll 10 times and average out the values, storing result into rawAccel array)
	//"poll","read","get"; reads raw data from sensor and returns it; maybe into a file? or an input stream? or a member variable of the class/struct? and then preprocess function can pull from that?
	//rawData type is a placeholder for now; will return raw sensor data

	virtual float preprocess()
	{
		//conversion of raw sensor data into relevant values based on constant offset values
		m_temp_processed = m_temp_raw * m_temp_offset;

		m_accel_processed[0] = m_accel_raw[0] * m_accel_offsets[0];
		m_accel_processed[1] = m_accel_raw[1] * m_accel_offsets[1];
		m_accel_processed[2] = m_accel_raw[2] * m_accel_offsets[2];

		m_gyro_processed[0] = m_gyro_raw[0] * m_gyro_offsets[0];
		m_gyro_processed[1] = m_gyro_raw[1] * m_gyro_offsets[1];
		m_gyro_processed[2] = m_gyro_raw[2] * m_gyro_offsets[2];
	}

	virtual void printSensorInfo()
	{
		std::cout << "Type: ADXL345" << endl;
		std::cout << "Number: " << getInstance() << endl;
		//std::cout << "Status:     " << getStatus() << endl;
		std::cout << "I2C BusID: " << getBusID() << endl;

		std::cout << "Temp_Raw: " << m_temp_raw << endl;
		std::cout << "Temp_Processed: " << m_temp_processed << endl;

		std::cout << "Accel_RawX: " << m_accel_raw[0] << endl;
		std::cout << "Accel_RawY: " << m_accel_raw[1] << endl;
		std::cout << "Accel_RawZ: " << m_accel_raw[2] << endl;
		std::cout << "Accel_ProcessedX: " << m_accel_processed[0] << endl;
		std::cout << "Accel_ProcessedY: " << m_accel_processed[1] << endl;
		std::cout << "Accel_ProcessedZ: " << m_accel_processed[2] << endl;

		std::cout << "Gyro_RawX: " << m_gyro_raw[0] << endl;
		std::cout << "Gyro_RawY: " << m_gyro_raw[1] << endl;
		std::cout << "Gyro_RawZ: " << m_gyro_raw[2] << endl;
		std::cout << "Gyro_ProcessedX: " << m_gyro_processed[0] << endl;
		std::cout << "Gyro_ProcessedY: " << m_gyro_processed[1] << endl;
		std::cout << "Gyro_ProcessedZ: " << m_gyro_processed[2] << endl;
	}

	void printRawValues()
	{
		std::cout << "======================================" << endl;
		std::cout << "Temp_Raw: " << m_temp_raw << endl;
		std::cout << "Accel_RawX: " << m_accel_raw[0] << endl;
		std::cout << "Accel_RawY: " << m_accel_raw[1] << endl;
		std::cout << "Accel_RawZ: " << m_accel_raw[2] << endl;
		std::cout << "Gyro_RawX: " << m_gyro_raw[0] << endl;
		std::cout << "Gyro_RawY: " << m_gyro_raw[1] << endl;
		std::cout << "Gyro_RawZ: " << m_gyro_raw[2] << endl;
		std::cout << "======================================" << endl;
	}

private:
	mraa::I2c m_i2c;
	float m_temp_raw;
	float m_temp_processed;
	float m_accel_raw[3];
	float m_accel_processed[3];
	float m_gyro_raw[3];
	float m_gyro_processed[3];
	float m_temp_offset;
	float m_accel_offsets[3]; //offsets for temp, accel, and gyro for proper calibration purposes
	float m_gyro_offsets[3];
	uint8_t m_buffer[BUFFER_SIZE];
}

#endif