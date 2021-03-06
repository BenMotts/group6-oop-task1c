#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "LoginMenu.h"
#include "ProfileMenu.h"

//UI Class for main menu (Store, login/view profile)
class MainMenu : public Menu
{
public:
	MainMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
};