#ifndef PLANE_H_
#define PLANE_H_

/** A plane has attributes to keep track of 
      1. when it arrived 
      2. when it begins servicing
      3. the time this plane needs to be serviced
      4. when it enters the departure queue
      5. when it is ready to take off 
*/
struct Plane
{
	Plane(int clock) : 
	arrival_time(clock), start_service_time(-1), service_time(-1), ready_takeoff_time(-1), enter_departure_time(-1)
	{}

	int arrival_time;					//enter landing queue
	int start_service_time;				//enter service queue
	int service_time;
	int enter_departure_time;			//enter departure queue
	int ready_takeoff_time;				//leave departure queue
};

#endif
