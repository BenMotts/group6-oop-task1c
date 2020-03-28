#include "LoginMenu.h"



LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn())
		for (int i(0); i < app->GetCurrentAccount()->GetUserCount(); ++i) {
			Option(i + 1, app->GetCurrentAccount()->GetUser(i)->GetUsername());
		}
	else {
		std::string email = Question("Enter Email");
		app->LoginAccount(email, Question("Enter Password"));
		if (!app->IsAccountLoggedIn())
			PrintLine("Invalid Email/Password Combination");
		else
			PrintLine("Account Logged In");
	}
}

bool LoginMenu::HandleChoice(const char& choice)
{
	int index = choice - '1';
	if (index >= 0 && index < app->GetCurrentAccount()->GetUserCount()) {
		if (app->LoginUser(app->GetCurrentAccount()->GetUser(index)->GetUsername(), Question("Enter Password"))) {
			return true;
		}
		else {
			BlockingMessage("Invalid Password");
			return false;
		}
	}
	BlockingMessage("Invalid Option");
	return false;
}
