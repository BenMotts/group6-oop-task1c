#pragma once
#include "Menu.h"
#include "Admin.h"

// Option menu for deleting a particular user (Admin availability only!)
class DeleteUserMenu : public Menu
{
public:
	DeleteUserMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
};

