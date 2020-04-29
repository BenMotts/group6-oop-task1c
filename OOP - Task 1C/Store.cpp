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

List<Game*> Store::SearchTitle(const std::string& text) const {
	List<Game*> toReturn;
	for (int i(0); i < games.length(); ++i)
		if (Utils::StartsWith(games[i]->GetName(), text))
			toReturn.addAtEnd(games[i]);
	return toReturn;
}

List<Game*> Store::SearchRange(const int& lower, const int& upper) const {
	List<Game*> toReturn;
	for (int i(0); i < games.length(); ++i)
		if (Utils::WithinRange(games[i]->GetCost(), lower, upper))
			toReturn.addAtEnd(games[i]);
	return toReturn;
}