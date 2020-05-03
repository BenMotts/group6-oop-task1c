#pragma once
#include "Menu.h"

class GameOptionsMenu : public Menu
{
public:
	GameOptionsMenu(LibraryItem* game, const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
private:
	LibraryItem* game;

};

