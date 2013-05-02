#include "User.h"


User::User(void):
	id(0), value(0)
{
}


User::~User(void)
{
}

int User::getId()
{
	return this->id;
}

bool User::setId(int &_id)
{
	if (_id > 0) {
		this->id = _id;
		return true;
	}
	else {
		return false;
	}
}

int User::getValue()
{
	return this->value;
}

bool User::setValue(int &_val)
{
	if (_val >= 0) {
		this->value = _val;
		return true;
	}
	else {
		return false;
	}
}