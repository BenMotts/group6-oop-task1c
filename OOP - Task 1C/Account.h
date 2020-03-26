#pragma once

#include <string>
#include "Player.h"
#include "List.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> users;
	private:
		std::string email;
		std::string password;
		Date created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};