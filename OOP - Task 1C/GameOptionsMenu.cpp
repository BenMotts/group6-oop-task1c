#include "GameOptionsMenu.h"



GameOptionsMenu::GameOptionsMenu(LibraryItem* game, const std::string& title, Application* app) :
	game(game), Menu(Utils::ToUpperRec(title), app)
{
	Paint();
}


void GameOptionsMenu::OutputOptions() {
	PrintLine(game->getDesc());
	PrintLine("Total Play Time: " + game->GetTimePlayed());
	PrintLine("Purchased: " + game->getDatePurchased().printDate());
	PrintLine("Rating: " + game->PrintRating());
	Line();
	Option('P', "Play Game");
	if (game->hasLiked() || game->hasDisliked())
		if (game->hasLiked()) {
			PrintLine("You have liked this game. Changed your mind?");
			Option('D', "Dislike");
		}
		else {
			PrintLine("You have disliked this game. Changed your mind?");
			Option('L', "Like");
		}
	else {
		Line();
		Option('L', "like");
		Option('D', "Dislike");
	}
}

bool GameOptionsMenu::HandleChoice(const char& choice) {
	//IF CHOICE == P, PLAY GAME HERE
	if (choice == 'P') {
		game->playGame();
		Paint();
		return true;
	}
	if (choice == 'D') {
		game->dislike();
		Paint();
		return true;
	}
	if (choice == 'L') {
		game->like();
		Paint();
		return true;
	}
	return false;
}