#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions() {
	if (!app->GetCurrentUser()->getLibrarySize())
		BlockingMessage("You have no games. Head to the store! Press return to continue");
	for (int i(0); i < app->GetCurrentUser()->getLibrarySize(); ++i) {
		Option(i + 1, app->GetCurrentUser()->getLibraryItem(i)->game->GetName() + ", Play Time: 5 hours");
	}
}

bool ProfileMenu::HandleChoice(char choice) {
	
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->getLibrarySize())
		BlockingMessage("To be implemented, add time to game");
	return false;
}