#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

	BirthdayParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {

		//add name to the front of room
		room.push_front(name);
		//get iterator to the front of the room (this points to the recently added party goer)
		std::list<std::string>::iterator itratr = room.begin();
		/*create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*Pass to the constructor "this" party, and the iterator from step 2*/
		BirthdayPartyTicket * party_ticket = new BirthdayPartyTicket(this, itratr);
		//return this new party ticket
		return party_ticket;
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		for (std::list<std::string>::iterator it = room.begin(); it != room.end(); it++) {
			std::cout << *it << " ";
		}
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {

		for (std::list<std::string>::iterator itr = room.begin(); itr != room.end(); itr++) {
			if (*itr == *it) {
				room.remove(*it);
				break;
			}
		}
	}
};

#endif