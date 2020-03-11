#pragma once
#include "Menu.h"

class LoginMenu : public Menu
{
public:
	LoginMenu(const std::string& title, Application* app);
	bool HandleInput();
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};

