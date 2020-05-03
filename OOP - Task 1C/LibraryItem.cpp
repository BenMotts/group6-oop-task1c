#include "LibraryItem.h"
#include "Utils.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(date), game(game), minutesPlayed(0)
{
	
}

LibraryItem::~LibraryItem()
{
}

const Date& LibraryItem::getDatePurchased() const {
	return purchased;
}

bool LibraryItem::hasLiked() const {
	return liked;
}

bool LibraryItem::hasDisliked() const {
	return disliked;
}

void LibraryItem::like() {
	if (!liked) {
		if (disliked == true) {
			game->removeDislike();
			disliked = false;
		}
		game->likeGame();
		liked = true;
	}
}

void LibraryItem::dislike() {
	if (!disliked) {
		if (liked == true) {
			game->removeLike();
			liked = false;
		}
		game->dislikeGame();
		disliked = true;
	}
}

std::string LibraryItem::getName() const {
	return game->GetName();
}

std::string LibraryItem::getDesc() const {
	return game->GetDescription();
}

std::string LibraryItem::PrintRating() const {
	return game->PrintRating();
}

void LibraryItem::playGame()
{
	minutesPlayed += Utils::RandomNumberGenerator(10, 60);
}

std::string LibraryItem::GetTimePlayed() const
{
	return Utils::formatTime(minutesPlayed);
}

bool LibraryItem::isGame(const Game* cmp) const {
	return game == cmp;
}