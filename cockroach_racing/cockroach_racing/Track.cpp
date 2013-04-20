#include "Track.h"


Track::Track(void)
{
}


Track::~Track(void)
{
}

int Track::getId()
{
	return this->id;
}

bool Track::setId(int _id)
{
	if (_id > 0) {
		this->id = _id;
		return true;
	}
	return false;
}

int Track::getWinnerId()
{
	return this->winner_id;
}

bool Track::setWinnerId(int _id)
{
	if (_id > 0) {
		this->winner_id = _id;
		return true;
	}
	return false;
}

int Track::getWinnerTeamId()
{
	return this->winner_team_id;
}

bool Track::setWinnerTeamId(int _team_id)
{
	if (_team_id > 0) {
		this->winner_team_id = _team_id;
		return true;
	}
	return false;
}
