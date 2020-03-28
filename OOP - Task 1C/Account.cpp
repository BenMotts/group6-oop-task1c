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

User* Account::GetUser(const int& index) {
	return users[index];
}

void Account::DeleteUser(User* const user) {
	users.deleteOne(user);
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

bool Account::CheckDetails(const std::string& email, const std::string& password) const {
	return this->email == email && this->password == password;
}

int Account::GetUserCount() const {
	return users.length();
}