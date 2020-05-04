#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created)
	: username(username), password(password), created(created)
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const bool User::CheckDetails(const std::string& username, const std::string& password) const {
	return username == this->username && password == this->password;
}

std::string User::SavedData()const {
	std::stringstream  os;

	os << created.printDate() + "\n";
	os <<username + "\n";
	os << password+"\n";
	

	return os.str();
}