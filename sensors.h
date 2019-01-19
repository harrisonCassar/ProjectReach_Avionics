#ifndef SENSORS_H

#define SENSORS_H

#include "globals.h"

rawData pollAll() {/*...*/}
//test mode function; will call construct datapacket function (abstracted function)
//switch statment, with each value corresponding to a series of if statements with global constants of "ACCEL1_IN_USE" and such (as described in "construct" function for datapacket)
//maybe return as a pointer to a dynamic array

//THIS ONE IS IN THE WORKS; IMPLEMENTATION STILL FIGURING OUT
rawData pollType(int typeMapping)
//polls all sensors of a certain type as indicated by inputted mapped values (find in globals.h file)
//switch statment, with each value corresponding to a series of if statements with global constants of "ACCEL1_IN_USE" and such (as described in "construct" function for datapacket)
//maybe return as a pointer to a dynamic array

rawData longPollAll() {/*...*/}
//takes pollAll over a longer period of time and averages out the values
//can potentially have a time input for customization purposes
//maybe return as a pointer to a dynamic array

rawData longPollType() {/*...*/}
//takes pollType over a longer period of time and averages out the values
//can potentially have a time input for customization purposes
//maybe return as a pointer to a dynamic array

//===================================================================================================================

bool getStatusAll() {/*...*/}
//test mode function; will call construct datapacket function (abstracted function)
//switch statment, with each value corresponding to a series of if statements with global constants of "ACCEL1_IN_USE" and such (as described in "construct" function for datapacket)
//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)
//maybe return a pointer to a dynamic array with all of the status? or just print to screen because this is an abstracted function?

//THIS ONE IS IN THE WORKS; IMPLEMENTATION STILL FIGURING OUT
bool getStatusType(int typeMapping) {/*...*/}
//polls all sensors of a certain type as indicated by inputted mapped values (find in globals.h file)
//switch statment, with each value corresponding to a series of if statements with global constants of "ACCEL1_IN_USE" and such (as described in "construct" function for datapacket)
//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)
//maybe return a pointer to a dynamic array with all of the status? or just print to screen because this is an abstracted function?

//===================================================================================================================

bool calibrateAll() {/*...*/}
//calls calibrate function of all active sensors
//returns true if successfull; false if otherwise (if one fails)
//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)
bool calibrateType() {/*...*/}
//calls calibrate function of all active sensors of one type
//returns true if successfull; false if otherwise (if one fails)
//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)

//===================================================================================================================

//EACH SENSOR WILL HAVE THEIR OWN CLASSES; THIS IS JUST TO INDICATE THAT EACH SENSOR WILL HAVE THESE GENERAL FUNCTIONS BUT MODIFIED IN SOME WAY
//have classes for each sensor type (maybe class inheritence with an overall "sensor" class, and have constructor that takes in pin value when declared in "main"; i.e. ACCELEROMETER accel1(ACCEL1_PIN);
class Sensor
{
public:
	Sensor(int pin) {/*...*/}
	//constructor that takes in pin number that sensor is connected to; this pin number would be used for all member functions

	bool calibrate() {/*...*/}
	//zeros sensor to current reading (different sensors will have slightly different implementations)
	//returns true if successfully calibrated; false otherwise
	//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)

	rawData poll() {/*...*/}
	//"poll","read","get"; reads raw data from sensor and returns it; maybe into a file? or an input stream? or a member variable of the class/struct? and then preprocess function can pull from that?
	//rawData type is a placeholder for now; will return raw sensor data

	rawData longPoll() {/*...*/}
	//call poll() over a longer period of time, averaging out the values (maybe allow time input functionality)
	//"poll","read","get"; reads raw data from sensor and returns it; maybe into a file? or an input stream? or a member variable of the class/struct? and then preprocess function can pull from that?
	//rawData type is a placeholder for now; will return raw sensor data

	//will be placed in sensors classes as a member function
	float preprocess() {/*...*/}
	//converts raw sensor data into relevant values and 

	bool getStatus() const {/*...*/}
	//return true if connected and avaiable; false if otherwise
	//return type can always be changed to an int to allow for more error returns (status constants described in systems.h or in globals.h files)

	int getDataRate() const {/*...*/}
	//returns the current set data rate

private:
	int m_pin;
	int m_datarate;
};

#endif