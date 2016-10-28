//I affirm that all code given below was written solely by me,
//Justice Martinez, and that any help I received adhered to 
//the rules stated for this exam.
#include "VehicleStuff.h"

//PT -- nice work. 100/100

void main()
{

	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = new Exam1::RaceCar("black");
	Garage[1] = new Exam1::Sedan("blue", 5);
	Garage[2] = new Exam1::Pickup("yellow", 600);

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}

	return;
}
