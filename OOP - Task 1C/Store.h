#pragma once

#include "Game.h"
#include "List.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <algorithm>

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
		void OrderByRating();
		void OrderByName();

	private:
		std::vector<Game*> games;
};