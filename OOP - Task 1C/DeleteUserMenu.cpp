#include "DeleteUserMenu.h"



DeleteUserMenu::DeleteUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void DeleteUserMenu::OutputOptions() {

	int adminCount = 0;

	for (int i(0); i < app->GetCurrentAccount()->GetUserCount(); ++i) {
		if (!dynamic_cast<Admin*>(app->GetCurrentAccount()->GetUser(i)))
			Option((i + 1) - adminCount, app->GetCurrentAccount()->GetUser(i)->GetUsername());
		else adminCount++;
	}
}

bool DeleteUserMenu::HandleChoice(const char& choice) {
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentAccount()->GetUserCount()) {
		if (DoubleCheckQuestion()) {
			for (int i(index); i < app->GetCurrentAccount()->GetUserCount(); ++i)
				if (!dynamic_cast<Admin*>(app->GetCurrentAccount()->GetUser(i))) {
					app->GetCurrentAccount()->DeleteUser(app->GetCurrentAccount()->GetUser(i));
					return true;
				}
		}
	}
	return false;
}