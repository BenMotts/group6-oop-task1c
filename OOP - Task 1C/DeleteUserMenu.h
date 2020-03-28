#pragma once
#include "Menu.h"
#include "Admin.h"

class DeleteUserMenu : public Menu
{
public:
	DeleteUserMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
};

