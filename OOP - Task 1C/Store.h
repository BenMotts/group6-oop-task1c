#pragma once

#include "Game.h"
#include "List.h"
#include "Utils.h"
#include <string>

class Store
{
	public:
		Store();
		~Store();
		void AddGame(Game*);
		Game* GetGame(const int&);
		int GetGameCount() const;
		List<Game*> SearchTitle(const std::string&) const;
		List<Game*> SearchRange(const int&, const int&) const;

	private:
		List<Game*> games;
};