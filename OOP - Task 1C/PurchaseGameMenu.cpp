#include "PurchaseGameMenu.h"
#include "Game.h"


PurchaseGameMenu::PurchaseGameMenu(Game* game, const std::string& title, Application* app)
	: game(game), Menu(Utils::ToUpperRec(title), app)
{
	Paint();
}

void PurchaseGameMenu::OutputOptions() {
	PrintLine(game->GetDescription());
	PrintLine("Cost: " + Utils::formatCredits(game->GetCost()));
	PrintLine("Player Rating: " + game->PrintRating());
	PrintLine("Age Rating: " + std::to_string(game->getAgeRating()));
	if (!app->IsUserLoggedIn())
		PrintLine("Log In To Purchase");
	else if (app->GetCurrentUser()->HasGame(game))
		PrintLine("You Already Own This Game");
	else if (app->GetCurrentUser()->HasEnoughCredits(game->GetCost())) {
		Line();
		Option('P', "Purchase Game");
	}
	else
		PrintLine("Insufficient Funds");
}

bool PurchaseGameMenu::HandleChoice(const char& choice) {

	if (app->IsUserLoggedIn() && choice == 'P' && !app->GetCurrentUser()->HasGame(game)) {
		if (app->GetCurrentUser()->HasEnoughCredits(game->GetCost()) && DoubleCheckQuestion()) {
			app->GetCurrentUser()->SpendCredits(game->GetCost());
			app->GetCurrentUser()->AddGame(new LibraryItem(Date(), game));
			return true;
		}
	}
	return false;
}
