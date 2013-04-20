#pragma once
#include "list.h"
#include "Stake.h"
#include "Track.h"
#include "User.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Broker
{
public:
	Broker(void);
	~Broker(void);
	List<Stake*> createStakeList();
	List<Track*> createTrackList();
	int createUserList(List<Track*> &trackList, List<Stake*> &stakeList);
	void createBrokerResultsFile();

	static string stakesFileName;
	static string raceResultsFileName;
	static string resultsFileName;
	static int brokerInterest;

	struct Exception
	{
		const char* text;
		int code;
		Exception(const char* _text, int _code) 
		{
			text=_text; 
			code=_code;
		}
	};

private:
	List<User*> userList;
	void addUniqueUserListElem(User* user);
};

