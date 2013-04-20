#pragma once
class Track
{
private:
    int id;
	int winner_id;
	int winner_team_id;

public:
	Track(void);
	~Track(void);

	int getId();
	bool setId(int _id);
	int getWinnerId();
	bool setWinnerId(int _id);
	int getWinnerTeamId();
	bool setWinnerTeamId(int _team_id);
};

