#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}

bool Account::usernameExists(const std::string& username) const {
	for (int i(0); i < users.length(); ++i)
		if (users[i]->GetUsername() == username)
			return true;
	return false;
}

void Account::AddUser(Player* const& player)
{
	users.addAtEnd(player);
}