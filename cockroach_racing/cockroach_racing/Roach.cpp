#include "Roach.h"


Roach::Roach(void)
{
}


Roach::~Roach(void)
{
}

int Roach::getId()
{
	return this->_id;
}

bool Roach::setId(int id)
{
	if (id > 0) {
		this->_id = id;
		return true;
	}
	return false;
}

int Roach::getTeamId()
{
	return this->_team_id;
}

bool Roach::setTeamId(int team_id)
{
	if (team_id > 0) {
		this->_team_id = team_id;
		return true;
	}
	return false;
}

int Roach::getPosition()
{
	return this->_position;
}

bool Roach::setPosition(int position)
{
	if (position > 0) {
		this->_position = position;
		return true;
	}
	return false;
}

