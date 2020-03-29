#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, const Game*);
		~LibraryItem();
		const Game *game;

	private:
		const Date purchased;
};