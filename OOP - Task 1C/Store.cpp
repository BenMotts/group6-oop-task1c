#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

void Store::AddGame(Game* game) {
	games.push_back(game);
}

Game* Store::GetGame(const int& index) {
	return games.at(index);
}

int Store::GetGameCount() const {
	return games.size();
}

List<Game*> Store::SearchTitle(const std::string& text) const {
	List<Game*> toReturn;
	for (int i(0); i < games.size(); ++i)
		if (Utils::StartsWith(games[i]->GetName(), text))
			toReturn.addAtEnd(games[i]);
	return toReturn;
}

List<Game*> Store::SearchRange(const int& lower, const int& upper) const {
	List<Game*> toReturn;
	for (int i(0); i < games.size(); ++i)
		if (Utils::WithinRange(games[i]->GetCost(), lower, upper))
			toReturn.addAtEnd(games[i]);
	return toReturn;
}

void Store::OrderByName() {
	std::sort(games.begin(), games.end(), Utils::CompareGameNames);
}

void Store::OrderByRating() {
	std::sort(games.begin(), games.end(), Utils::CompareGameRatings);
}