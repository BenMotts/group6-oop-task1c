#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsAccountLoggedIn()) {
		if (app->IsUserLoggedIn())
		{
			Option('P', "View Profile");
			Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
		}
		else
		{
			Option('L', "Login User");
			Option('Q', "Logout Account");
		}
	}
	else {
		Option('L', "Login Account");
	}
}

bool MainMenu::HandleChoice(const char& choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsAccountLoggedIn() && app->IsUserLoggedIn()) {
			if (DoubleCheckQuestion())
				app->LogoutUser();
		}
		else
		{
			LoginMenu("LOGIN", app);
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			ProfileMenu("PROFILE: " + app->GetCurrentUser()->GetUsername(), app);
		}
	} break;
	case 'Q':
	{
		if (DoubleCheckQuestion())
			app->LogoutAccount();
		break;
	}
	}
	return false;
}