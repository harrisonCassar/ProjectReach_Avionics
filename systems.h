#ifndef SYSTEMS_H

#define SYSTEMS_H

#include 

//EACH SYSTEM WILL HAVE THEIR OWN CLASSES; THIS IS JUST TO INDICATE THAT EACH SYSTEM WILL HAVE THESE GENERAL FUNCTIONS BUT MODIFIED IN SOME WAY
//have classes for each system type (maybe class inheritence with an overall "system" class, and have constructor that takes in what port connected to when declared in "main")
class System
{
public:
	System(char* connectionType, int dataRate) {/*...*/}
	//connection type parameter currently set to a string input, but probably easier to simply map to global constant
	//dataRate of connection; do not currently know exact connection types, and therefore might not be needed

	int getStatus() const {/*...*/}
	//returns value depending on status; as determined by global constants
	//i.e. 	0: not connected/powered off
	//		1: idle, waiting for command
	//		2: ready to recieve data
	//		3: ready to send data

	bool isConnected() const {/*...*/}
	//less abstracted "getStatus" function, specifically implements the check for being connected via wire

	int getDataRate() const {/*...*/}
	//returns the current set data rate

	bool setDataRate() {/*...*/}
	//returns true if successfully set datarate; false otherwise

private:
	int m_datarate;
	char* connectionType;
};

#endif