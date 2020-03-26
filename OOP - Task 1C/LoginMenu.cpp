#include "LoginMenu.h"



LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	for (int i(0); i < app->GetCurrentAccount()->users.length(); ++i) {
		Option(i + 1, app->GetCurrentAccount()->users[i]->GetUsername());
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentAccount()->users.length()) {
		if (app->LoginUser(app->GetCurrentAccount()->users[index]->GetUsername(), Question("Enter Password"))) {
			return true;
		}
		else {
			BlockingMessage("Invalid Password");
			return false;
		}
	}
	BlockingMessage("Invalid Option, Press return to continue");
	return false;
}
