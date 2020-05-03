#pragma once
#include "Menu.h"


// UI Class for user interaction options when selecting a game on profile page
class GameOptionsMenu : public Menu
{
public:
	GameOptionsMenu(LibraryItem* game, const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
private:
	LibraryItem* game;

};

