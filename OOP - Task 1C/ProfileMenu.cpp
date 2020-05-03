#include "ProfileMenu.h"


ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions() {

	PrintLine("Credits: " + Utils::formatCredits(app->GetCurrentUser()->GetCredits()));
	Option('C', "Add Credits");

	if (!app->GetCurrentUser()->HasGames())
		PrintLine("You have no games. Head to the store!");
	else {
		PrintLine("Play Games");
		for (int i(0); i < app->GetCurrentUser()->GetLibrarySize(); ++i) {
			Option(i + 1, app->GetCurrentUser()->GetLibraryItem(i)->game->GetName() + ", Play Time: "  + app->GetCurrentUser()->GetLibraryItem(i)->GetTimePlayed());
		}
		Line();
		Option('T', "Sort Games By Date Purchased");
		Option('N', "Sort Games By Name");
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
	else if (dynamic_cast<Admin*>(app->GetCurrentUser()) && (choice=='A' || choice == 'D')) {
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
	else if (choice == 'T' && app->GetCurrentUser()->HasGames()) {
		app->GetCurrentUser()->OrderGamesByDate();
		Paint();
		return true;
	}
	else if (choice == 'N' && app->GetCurrentUser()->HasGames()) {
		app->GetCurrentUser()->OrderGamesByName();
		Paint();
		return true;
	}
	else {
		int index = choice - '1';

		if (index >= 0 && index < app->GetCurrentUser()->GetLibrarySize()) {
			GameOptionsMenu(app->GetCurrentUser()->GetLibraryItem(index), app->GetCurrentUser()->GetLibraryItem(index)->getName(), app);
			app->GetCurrentUser()->GetLibraryItem(index)->playGame();
		}
		return false;
	}
	return false;
}