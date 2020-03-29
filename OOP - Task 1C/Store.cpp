#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	games.~List();
}

void Store::AddGame(Game* game) {
	games.addAtEnd(game);
}

Game* Store::GetGame(const int& index) {
	return games[index];
}

int Store::GetGameCount() const {
	return games.length();
}