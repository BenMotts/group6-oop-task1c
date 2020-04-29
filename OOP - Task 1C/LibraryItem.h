#pragma once

#include "Utils.h"
#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, const Game*);
		~LibraryItem();
		const Game *game;

		void playGame();

		std::string GetTimePlayed() const;

	private:
		const Date purchased;
		int minutesPlayed;
};