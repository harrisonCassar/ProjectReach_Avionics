#ifndef SENSORS_H

#define SENSORS_H

#include "globals.h"


rawData pollAll() {/*...*/}
//test mode function; will call construct datapacket function (abstracted function)

//THIS ONE IS IN THE WORKS; IMPLEMENTATION STILL UNKNOWN 
rawData pollType(int typeMapping)
//polls all sensors of a certain type as indicated by inputted mapped values (find globals.h file)




//EACH SENSOR WILL HAVE THEIR OWN CLASSES; THIS IS JUST TO INDICATE THAT EACH SENSOR WILL HAVE THESE GENERAL FUNCTIONS BUT MODIFIED IN SOME WAY
class sensor
{


rawData poll() {/*...*/}
//"poll","read","get"; reads raw data from sensor and returns it; maybe into a file? or an input stream? and then preprocess function can pull from that?


	//will be placed in sensors classes as a member function
float preprocess() {/*...*/}
//converts raw sensor data into relevant values and 
//rawData type is a placeholder for now. "get" or "read" function for sensor will return raw sensor data



bool getStatus() {/*...*/}
//return true if good; false if otherwise

};





#endif