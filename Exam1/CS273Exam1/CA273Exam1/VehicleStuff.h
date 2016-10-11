//I affirm that all code given below was written solely by me,
//Justice Martinez, and that any help I received adhered to 
//the rules stated for this exam.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};

	// STEP 1: Complete the implementation of the Vehicle base class 
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:
		Vehicle(string color) {
			this->_color = color;
		}
		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar:public Vehicle {
	public:
		//Top speed: 250mph
		//Wheel radius: 305mm
		RaceCar(string color) : Vehicle(color) {
			this->_topspeed = 250;
			for (int i = 0; i < 4; i++) {
				wheels.push_back(305);
			}
		}
		void Description() {
			cout << "I am a " << _color << " race car that can race at "
				<< _topspeed << "mph. Vrooom!\n";
		}

	};

	class Sedan:public Vehicle {
	public:
		//Top speed: 95mph
		//Wheel radius: 381mm
		int number_of_seats;
		Sedan(string color, int seats) : Vehicle(color) {
			this->number_of_seats = seats;
			this->_topspeed = 95;
			for (int i = 0; i < 4; i++) {
				wheels.push_back(381);
			}
		}
		void Description() {
			cout << "I am a " << _color << " sedan that can carry " << number_of_seats
				<< " people at " << _topspeed << "mph. Yea!\n";
		}

	};

	class Pickup:public Vehicle {
	public:
		//Top speed: 85mph
		//Wheel radius: 432mm
		int hauling_capacity;
		Pickup(string color,int capacity) : Vehicle(color) {
			this->hauling_capacity = capacity;
			this->_topspeed = 85;
			for (int i = 0; i < 4; i++) {
				wheels.push_back(432);
			}
		}
		void Description() {
			cout << "I am a " << _color << " pickup that can haul " <<
				hauling_capacity << " sq. feet at " << _topspeed << "mph.\n";
		}

	};
}
