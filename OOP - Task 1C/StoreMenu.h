#pragma once

#include "Menu.h"
#include "PurchaseGameMenu.h"

#include <string>
#include <vector>
#include <math.h>

//UI Class for the entire store (Ability to search/order games)
class StoreMenu
	: public Menu
{
public:
	StoreMenu(const std::string& title, Application * app, int);
	StoreMenu(const std::string& title, Application * app, List<Game*> games, int);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;

private:
	List<Game*> games;
	bool searchView;
	int pageNum;
	const int MAX_GAMES = 5;
};