#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, const Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

Date LibraryItem::getDatePurchased() const {
	return purchased;
}