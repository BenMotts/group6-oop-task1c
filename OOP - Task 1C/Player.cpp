#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
}

void Player::AddGame(LibraryItem* item) {
	library.push_back(item);
}

LibraryItem* Player::GetLibraryItem(const int& index) const {
	return library[index];
}

bool Player::HasGame(const Game* game) const {
	for (int i(0); i < library.size(); ++i)
		if (library[i]->game == game)
			return true;
	return false;
}

int Player::GetLibrarySize() const {
	return library.size();
}

bool Player::HasEnoughCredits(const int& amt) const {
	assert(amt >= 0);
	return (credits - amt >= 0);
}

int Player::GetCredits() const {
	return credits;
}

void Player::SpendCredits(const int& amt) {
	if (HasEnoughCredits(amt))
		credits -= amt;
}

void Player::AddCredits(const int& amt) {
	if (amt > 0)
		credits += amt;
}

void Player::OrderGamesByDate() {
	std::sort(library.begin(), library.end(), Utils::PurchasedAfter);
}


void Player::OrderGamesByName() {
	std::sort(library.begin(), library.end(), Utils::CompareLibraryItemNames);
}
