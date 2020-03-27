#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions() {
	if (!app->GetCurrentUser()->getLibrarySize())
		BlockingMessage("You have no games. Head to the store!/nPress return to continue");
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

bool ProfileMenu::HandleChoice(char choice) {

	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->getLibrarySize() + 2) {
		if (index < app->GetCurrentUser()->getLibrarySize())
			BlockingMessage("To be implemented, add time to game");
		else if (index == app->GetCurrentUser()->getLibrarySize()) {
			std::string newUsername = Question("Enter Username");
			if (app->GetCurrentAccount()->usernameExists(newUsername)) {
				BlockingMessage("Username already exists. Press return to continue..");
				return false;
			}
			else {
				app->GetCurrentAccount()->AddUser(new Player(newUsername, Question("Enter Password"), Date()));
				return true;
			}
		}
		else
			BlockingMessage("To be implemented, delete user");
	}
	return false;
}