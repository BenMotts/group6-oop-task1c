#include "ProfileMenu.h"


ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions() {

	PrintLine("Credits: " + Utils::formatCredits(app->GetCurrentUser()->GetCredits()));
	Option('C', "Add Credits");

	if (!app->GetCurrentUser()->GetLibrarySize())
		PrintLine("You have no games. Head to the store!");
	else {
		PrintLine("Play Games");
		for (int i(0); i < app->GetCurrentUser()->GetLibrarySize(); ++i) {
			Option(i + 1, app->GetCurrentUser()->GetLibraryItem(i)->game->GetName() + ", Play Time: 5 hours");
		}
	}
	if (dynamic_cast<Admin*>(app->GetCurrentUser())) {
		PrintLine("Admin Tools");
		Option('A', "Add User");
		Option('D', "Delete User");
	}
}

bool ProfileMenu::HandleChoice(const char& choice) {

	if (choice == 'C') {
		std::string amt = Question("Enter Amount");
		if (Utils::isInteger(amt) && stoi(amt) > 0) {
			app->GetCurrentUser()->AddCredits(std::stoi(amt) * 100);
			BlockingMessage("Credits Added");
			return true;
		}
		else
			BlockingMessage("Invalid Amount"); {
			return false;
		}
	}
	else if (dynamic_cast<Admin*>(app->GetCurrentUser())) {
		if (choice == 'A') {
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
		else if (choice == 'D') {
			DeleteUserMenu("DELETE USER", app);
		}
	}
	else {
		int index = choice - '1';

		if (index >= 0 && index < app->GetCurrentUser()->GetLibrarySize()) {
			if (index < app->GetCurrentUser()->GetLibrarySize())
				BlockingMessage("To be implemented, add time to game");
		}
		return false;
	}
	return false;
}