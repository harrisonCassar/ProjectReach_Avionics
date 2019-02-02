#ifndef ADXL345_H

#define ADXL_345_H

#include "sensors.h"

//accel
class ADXL345: public Sensor
{
public:
	ADXL345(int busID):Sensor(busID, );

	virtual bool calibrate() {/*...*/}
	//zeros sensor to current reading (different sensors will have slightly different implementations)
	//returns true if successfully calibrated; false otherwise
	//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)
	//supports 
private:


}

#endif ADXL345_H