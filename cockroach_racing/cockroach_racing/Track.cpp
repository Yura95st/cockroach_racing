#include "Track.h"


Track::Track(void)
{
}


Track::~Track(void)
{
}

int Track::getId()
{
	return this->_id;
}

bool Track::setId(int id)
{
	if (id > 0) {
		this->_id = id;
		return true;
	}
	return false;
}

void Track::setNewRoach(Roach* roach)
{
	this->_roach_list.add(roach);
}

Roach* Track::getWinner()
{
	for (int i=0, count = _roach_list.count(); i<count; ++i) {
		Roach* roach = _roach_list.find(i)->value;
		if (roach->getPosition() == 1) {
			return roach;
		}
	}
	return NULL;
}