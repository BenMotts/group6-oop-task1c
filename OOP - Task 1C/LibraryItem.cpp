#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(date), game(game)
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
		if (disliked = true) {
			game->removeDislike();
			disliked = false;
		}
		game->likeGame();
		liked = true;
	}
}

void LibraryItem::dislike() {
	if (!disliked) {
		if (liked = true) {
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
