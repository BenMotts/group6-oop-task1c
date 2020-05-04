#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : searchView(false), Menu(title, app)
{
	Paint(); // required in constructor
}

StoreMenu::StoreMenu(const std::string& title, Application * app, List<Game*> games) : searchView(true), games(games), Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
if (!games.isEmpty() && searchView)
		for (int i(0); i < games.length(); ++i) {
				Option(i + 1, games[i]->GetName() + " - Rating: " + games[i]->PrintRating());
		}
	else if (searchView)
		PrintLine("No Results Matching Your Criteria");
	else
		for (int i = 0; i < app->GetStore().GetGameCount(); i++)
			Option(i + 1, app->GetStore().GetGame(i)->GetName() + " - Rating: " + app->GetStore().GetGame(i)->PrintRating());

	Line();
	PrintLine("PAGE 1 / 2");
	Option('N', "Next Page");
	Option('R', "Order By Player Rating");
	Option('N', "Order By Name");
	Option('S', "Search By Name");
	Option('P', "Search By Price Range");
}

bool StoreMenu::HandleChoice(const char& choice)
{
	// If player wants to search the store by name
	if (choice == 'S') {
		std::string searchText = Question("Search For");
		StoreMenu("Search: " + searchText, app, app->GetStore().SearchTitle(searchText));
		return true;
	}
	//If player wants to search the store by price
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
	//If player wants to order the games by ratings
	else if (choice == 'R') {
		app->GetStore().OrderByRating();
		Paint();
		return true;
	}
	//If player wants to order the games by name
	else if (choice == 'N'){
		app->GetStore().OrderByName();
		Paint();
		return true;
	}
	else {
		//Player wants to view game information
		int index = choice - '1';

		if (!games.isEmpty() && index >= 0 && index < games.length()) {
			PurchaseGameMenu(games[index], games[index]->GetName(), app);
		} else if (index >= 0 && index < app->GetStore().GetGameCount()) {
			PurchaseGameMenu(app->GetStore().GetGame(index), app->GetStore().GetGame(index)->GetName(), app);
		}
	}
	return false;
}