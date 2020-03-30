#include "LibraryItem.h"

//test comment
LibraryItem::LibraryItem(const std::string& date, Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}