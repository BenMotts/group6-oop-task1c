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
		bool usernameExists(const std::string&) const;
		bool CheckDetails(const std::string&, const std::string&) const;
		void AddUser(Player* const&);
		User* GetUser(const int&);
		int GetUserCount() const;
		void DeleteUser(User* const);
		std::string GetSavedData()const;
		
	private:
		List<User*> users;
		std::string email;
		std::string password;
		Date created;  
};