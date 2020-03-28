#include "ProfileMenu.h"


ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions() {
	if (!app->GetCurrentUser()->getLibrarySize())
		BlockingMessage("You have no games. Head to the store!");
	int optionNum = 0;
	for (optionNum; optionNum < app->GetCurrentUser()->getLibrarySize(); ++optionNum) {
		Option(optionNum + 1, app->GetCurrentUser()->getLibraryItem(optionNum)->game->GetName() + ", Play Time: 5 hours");
	}
	if (dynamic_cast<Admin*>(app->GetCurrentUser())) {
		Line();
		Option(optionNum += 1, "Add User");
		Option(optionNum += 1, "Delete User");
	}
}

bool ProfileMenu::HandleChoice(const char& choice) {

	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->getLibrarySize() + 2) {
		if (index < app->GetCurrentUser()->getLibrarySize())
			BlockingMessage("To be implemented, add time to game");
		if (dynamic_cast<Admin*>(app->GetCurrentUser())) { // If user is an admin
			if (index == app->GetCurrentUser()->getLibrarySize()) {	// If user wants to add a new user
				std::string newUsername = Question("Enter Username");
				if (app->GetCurrentAccount()->usernameExists(newUsername) || !newUsername.size()) {
					BlockingMessage("Username already exists");
					return false;
				}
				else {
					app->GetCurrentAccount()->AddUser(new Player(newUsername, Question("Enter Password"), Date()));
					return true;
				}
			}
			else if (index == app->GetCurrentUser()->getLibrarySize() + 1)	// If user wants to delete a new user
				DeleteUserMenu("DELETE USER", app);
		}
	}
	return false;
}