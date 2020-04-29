#include "LibraryItem.h"


LibraryItem::LibraryItem(const Date& date, const Game* game)
	: purchased(date), game(game), minutesPlayed(0)
{
	
}

LibraryItem::~LibraryItem()
{
}

void LibraryItem::playGame()
{
	minutesPlayed += Utils::RandomNumberGenerator(10, 60);
}

std::string LibraryItem::GetTimePlayed() const
{
	return Utils::formatTime(minutesPlayed);
}


