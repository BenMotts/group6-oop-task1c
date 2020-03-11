#pragma once

#include <string>
#include "Player.h"
#include <vector>

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		std::vector<User*> users;
		//User* users[3] = { }; // TODO: replace with custom List<T> class
	private:
		std::string email;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};