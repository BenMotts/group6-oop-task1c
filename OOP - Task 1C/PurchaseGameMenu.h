#pragma once
#include "Menu.h"
class PurchaseGameMenu : public Menu
{
public:
	PurchaseGameMenu(const Game* game, const std::string& title,  Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
private:
	const Game* game;
};

