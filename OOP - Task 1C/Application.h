#pragma once

#include "List.h"
#include "Account.h"
#include "Admin.h"
#include "User.h"
#include "Store.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		void LogoutAccount();
		void AddAccount(Account* const&);
		void AddUser(Player* const&);
		int GetAccountCount() const;
		void Load();
		void Save();
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
		List<Account*> accounts;
};