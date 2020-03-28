#pragma once
#include "Menu.h"

class LoginMenu : public Menu
{
public:
	LoginMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(const char& choice) final;
};

