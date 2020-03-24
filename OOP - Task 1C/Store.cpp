#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	games.~List();
}

void Store::addGame(Game* game) {
	games.addAtEnd(game);
}

Game* Store::getGame(const int& index) {
	return games[index];
}
