#pragma once

#include "Game.h"
#include "List.h"
#include <string>

class Store
{
	public:
		Store();
		~Store();
		void AddGame(Game*);
		Game* GetGame(const int&);
		int GetGameCount() const;

	private:
		List<Game*> games;
		//TODO search store
};