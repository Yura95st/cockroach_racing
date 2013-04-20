#pragma once
class Stake
{
private:
	int id;
    int user_id;
    int track_id;
    int team_id;
    int value;

public:
	Stake(void);
	~Stake(void);
	int getId();
	bool setId(int _id);
	int getUserId();
	bool setUserId(int _user_id);
	int getTrackId();
	bool setTrackId(int _track_id);
	int getTeamId();
	bool setTeamId(int _team_id);
	int getValue();
	bool setValue(int _value);
};

