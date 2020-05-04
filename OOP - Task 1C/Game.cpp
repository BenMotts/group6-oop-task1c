#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating,const int& GameID,int likes,int dislikes)
	: name(name), description(desc), cost(cost), ageRating(rating),GameID(GameID), likes(likes), dislikes(dislikes)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}

int Game::getLikeRating() const {
	if (likes == 0)
		return 0;
	if (dislikes == 0)
		return 100;
	return (100 / (likes + dislikes)) * likes;
}


void Game::likeGame() {
	likes++;
}

void Game::dislikeGame() {
	dislikes++;
}

void Game::removeLike() {
	if (likes > 0)
	likes--;
}

void Game::removeDislike() {
	if (dislikes > 0)
		dislikes--;
}

int Game::getAgeRating() const {
	return ageRating;
}

std::string Game::PrintRating() const {
	if (likes == 0 && dislikes == 0)
		return "N/A";
	if (likes == 0 && dislikes)
		return "0%";
	if (dislikes == 0 && likes)
		return "100%";
	return std::to_string((100 / (likes + dislikes)) * likes) + '%';
}
int Game::GetGameID()const {
	
	return GameID;
}