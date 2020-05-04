#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app, int pageNum)
	: searchView(false), Menu(title, app), pageNum(pageNum)
{
	Paint(); // required in constructor
}

StoreMenu::StoreMenu(const std::string& title, Application * app, List<Game*> games, int pageNum)
	: searchView(true), games(games), Menu(title, app), pageNum(pageNum)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	int maxIndex;
	if (!games.isEmpty() && searchView) {
		if (pageNum * MAX_GAMES < games.length())
			maxIndex = MAX_GAMES * pageNum;
		else maxIndex = games.length();
		for (int i = (MAX_GAMES * pageNum) - MAX_GAMES; i < maxIndex; ++i) {
			Option((i - (MAX_GAMES * (pageNum - 1))) + 1, games[i]->GetName() + " - Rating: " + games[i]->PrintRating());
		}
	}
	else if (searchView)
		PrintLine("No Results Matching Your Criteria");
	else {
		if (pageNum * MAX_GAMES < app->GetStore().GetGameCount())
			maxIndex = MAX_GAMES * pageNum;
		else maxIndex = app->GetStore().GetGameCount();
		for (int i = (MAX_GAMES * pageNum) - MAX_GAMES; i < maxIndex; i++)
			Option((i - (MAX_GAMES * (pageNum - 1))) + 1, app->GetStore().GetGame(i)->GetName() + " - Rating: " + app->GetStore().GetGame(i)->PrintRating());
	}
	Line();
	if (searchView) {
		if (!games.isEmpty())
			PrintLine("PAGE " + std::to_string(pageNum) + " / " + std::to_string((int)std::ceil(games.length() / (float)MAX_GAMES))); {
			if (pageNum != (int)std::ceil(games.length() / (float)MAX_GAMES))
				Option('N', "Next Page");
			else Line();
		}
	}
	else {
		PrintLine("PAGE " + std::to_string(pageNum) + " / " + std::to_string((int)std::ceil(app->GetStore().GetGameCount() / (float)MAX_GAMES)));
		if (pageNum != (int)std::ceil((int)std::ceil(app->GetStore().GetGameCount() / (float)MAX_GAMES)))
			Option('N', "Next Page");
		else Line();
	}
	Option('R', "Order By Player Rating");
	Option('A', "Order By Name");
	Option('S', "Search By Name");
	Option('P', "Search By Price Range");
}

bool StoreMenu::HandleChoice(const char& choice)
{
	// If player wants to search the store by name
	if (choice == 'S') {
		std::string searchText = Question("Search For");
		StoreMenu("Search: " + searchText, app, app->GetStore().SearchTitle(searchText), 1);
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
				StoreMenu("Price Between: " + lowerValueStr + " and " + upperValueStr, app, app->GetStore().SearchRange(lowerValue * 100.0f, upperValue * 100.0f), 1);
				return true;
			}
		}
		return false;
	}
	//If player wants to order the games by ratings
	else if (choice == 'R') {
		app->GetStore().OrderByRating();
		StoreMenu("STORE", app, 1);
		return true;
	}
	//If player wants to order the games by name
	else if (choice == 'A') {
		app->GetStore().OrderByName();
		StoreMenu("STORE", app, 1);
		return true;
	}
	else if (choice == 'N') {
		if (searchView) {
			if (!games.isEmpty() && pageNum * MAX_GAMES < games.length())
				StoreMenu("STORE", app, games, pageNum + 1);
		}
		else {
			if (pageNum * MAX_GAMES < app->GetStore().GetGameCount())
				StoreMenu("STORE", app, pageNum + 1);
		}
	}
	else {
		//Player wants to view game information
		int index = (choice - '1') + (MAX_GAMES * pageNum) - MAX_GAMES;
		//MAX_GAMES * pageNum) - MAX_GAMES
		if (!games.isEmpty() && index >= 0 && index < games.length()) {
			PurchaseGameMenu(games[index], games[index]->GetName(), app);
		}
		else if (index >= 0 && index < app->GetStore().GetGameCount()) {
			PurchaseGameMenu(app->GetStore().GetGame(index), app->GetStore().GetGame(index)->GetName(), app);
		}
	}
	return false;
}