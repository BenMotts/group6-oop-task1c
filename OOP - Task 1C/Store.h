#pragma once

#include "Game.h"
#include "List.h"
#include <string>

class Store
{
	public:
		Store();
		~Store();
		void addGame(Game*);
		Game* getGame(const int&);

	private:
		List<Game*> games;

};