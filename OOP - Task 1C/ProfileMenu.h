#pragma once
#include "Menu.h"
#include "Admin.h"
#include "DeleteUserMenu.h"
#include "GameOptionsMenu.h"

//UI Class for user menu (Can play games, admin functions, etc)
class ProfileMenu :
	public Menu
{
public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
};

