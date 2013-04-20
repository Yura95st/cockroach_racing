#pragma once
#include <iostream>
using namespace std;

class User
{
public:
	User(void);
	~User(void);
	int getId();
	bool setId(int &_id);
	int getValue();
	bool setValue(int &_val);
	void out();

private:
	int id;
	int value;
};

