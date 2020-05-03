#pragma once
#include "Menu.h"

//UI class to purchase a game
class PurchaseGameMenu : public Menu
{
public:
	PurchaseGameMenu(Game* game, const std::string& title,  Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
private:
	Game* game;
};

