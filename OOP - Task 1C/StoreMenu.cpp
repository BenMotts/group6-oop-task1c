#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

StoreMenu::StoreMenu(const std::string& title, Application * app, List<Game*> games) : games(games), Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	if (games.length())
		for (int i(0); i < games.length(); ++i)
			Option(i + 1, games[i]->GetName());
	else
		for (int i = 0; i < app->GetStore().GetGameCount(); i++)
			Option(i + 1, app->GetStore().GetGame(i)->GetName());

	Line();

	Option('S', "Search By Name");
	Option('P', "Search By Price");
}

bool StoreMenu::HandleChoice(const char& choice)
{
	if (choice == 'S') {
		std::string searchText = Question("Search For");
		StoreMenu("Search: " + searchText, app, app->GetStore().SearchTitle(searchText));
		return true;
	}
	else if (choice == 'P') {
		std::string lowerValueStr = Question("Enter Lower Limit");
		if (Utils::isInteger(lowerValueStr) && std::stoi(lowerValueStr) >= 0) {
			int lowerValue = stoi(lowerValueStr);
			std::string upperValueStr = Question("Enter Upper Limit");
			if (Utils::isInteger(upperValueStr) && std::stoi(upperValueStr) > lowerValue) {
				int upperValue = stoi(upperValueStr);
				StoreMenu("Price Between: " + lowerValueStr + " and " + upperValueStr, app, app->GetStore().SearchRange(lowerValue * 100.0f, upperValue * 100.0f));
				return true;
			}
		}
		return false;
	} 
	else {

		int index = choice - '1';

		if (games.length() && index >= 0 && index < games.length()) {
			Game* gamePointer = games[index];
			PurchaseGameMenu(gamePointer, gamePointer->GetName(), app);
		} else if (index >= 0 && index < app->GetStore().GetGameCount()) {
			Game* gamePointer = app->GetStore().GetGame(index);
			PurchaseGameMenu(gamePointer, gamePointer->GetName(), app);
		}
	}

	return false;
}