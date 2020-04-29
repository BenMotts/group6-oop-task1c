#pragma once
#include "Game.h"
class PlayGame 
{
public:
	PlayGame();
	~PlayGame();
	
private:
	const Game *game;

	bool isPlaying;
	int hoursPlayed;
	int getHoursPlayed();
	void setHoursPlayed();
};
