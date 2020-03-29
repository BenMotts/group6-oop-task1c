#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
	library.~List();
}

void Player::AddGame(LibraryItem* item) {
	library.addAtEnd(item);
}

LibraryItem* Player::GetLibraryItem(const int& index) const {
	return library[index];
}

bool Player::HasGame(const Game* game) const {
	for (int i(0); i < library.length(); ++i)
		if (library[i]->game == game)
			return true;
	return false;
}

int Player::GetLibrarySize() const {
	return library.length();
}

bool Player::HasEnoughCredits(const int& amt) const {
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