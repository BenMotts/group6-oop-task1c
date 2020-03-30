#pragma once

#include "Menu.h"
#include "PurchaseGameMenu.h"

#include <string>
#include <vector>

class StoreMenu
	: public Menu
{
public:
	StoreMenu(const std::string& title, Application * app);
	StoreMenu(const std::string& title, Application * app, List<Game*> games);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;

private:
	List<Game*> games;
};