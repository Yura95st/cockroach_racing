#pragma once
class Roach
{
public:
	Roach(void);
	~Roach(void);
	int getId();
	bool setId(int id);
	int getTeamId();
	bool setTeamId(int team_id);
	int getPosition();
	bool setPosition(int position);

private:
	int _id;
	int _team_id;
	int _position;
};

