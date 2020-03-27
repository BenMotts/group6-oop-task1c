#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
	}
	else
	{
		Option('L', "Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure (Y / N)?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();
			}
		}
		else
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
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
	}
	return false;
}