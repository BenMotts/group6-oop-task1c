#include "LoginMenu.h"



LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	for (int i(0); i < app->GetCurrentAccount()->users.size(); ++i) {
		Option(i + 1, app->GetCurrentAccount()->users.at(i)->GetUsername());
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentAccount()->users.size()) {
		if (app->LoginUser(app->GetCurrentAccount()->users.at(index)->GetUsername(), Question("Enter Password"))) {
			return true;
		}
		else {
			BlockingMessage("Invalid Password");
			return false;
		}
	}
	BlockingMessage("Invalid Option, Press Return To Retry");
	return false;
}
