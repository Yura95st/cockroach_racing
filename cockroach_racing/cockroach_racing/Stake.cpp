#include "Stake.h"


Stake::Stake(void)
{
}


Stake::~Stake(void)
{
}

int Stake::getId()
{
	return this->id;
}

bool Stake::setId(int _id)
{
	if (_id > 0) {
		this->id = _id;
		return true;
	}
	return false;
}

int Stake::getUserId()
{
	return this->user_id;
}

bool Stake::setUserId(int _user_id)
{
	if (_user_id > 0) {
		this->user_id = _user_id;
		return true;
	}
	return false;
}

int Stake::getTrackId()
{
	return this->track_id;
}

bool Stake::setTrackId(int _track_id)
{
	if (_track_id > 0) {
		this->track_id = _track_id;
		return true;
	}
	return false;
}

int Stake::getTeamId()
{
	return this->team_id;
}

bool Stake::setTeamId(int _team_id)
{
	if (_team_id > 0) {
		this->team_id = _team_id;
		return true;
	}
	return false;
}

int Stake::getValue()
{
	return this->value;
}

bool Stake::setValue(int _value)
{
	if (_value > 0) {
		this->value = _value;
		return true;
	}
	return false;
}

