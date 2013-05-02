#pragma once
#include "Roach.h"
#include "list.h"

class Track
{
public:
	Track(void);
	~Track(void);
	int getId();
	bool setId(int id);
	void Track::setNewRoach(Roach* roach);
	Roach* getWinner();

private:
	int _id;
	List<Roach*> _roach_list;
};

