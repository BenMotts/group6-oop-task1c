#pragma once
#include "Menu.h"
#include "Admin.h"

class ProfileMenu :
	public Menu
{
public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};

