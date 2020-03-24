#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	accounts.~List();
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];
	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: Update to algorythm to speed up login/decrease code amount
	for (int i(0); i < currentAccount->users.length(); ++i) {
		if (currentAccount->users[i]->CheckDetails(username, password)) {
			currentUser = currentAccount->users[i];
			return true;
		}
	}
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::AddAccount(Account* const& acc) {
	accounts.addAtEnd(acc);
	if (currentAccount == nullptr)
		currentAccount = acc;
}

void Application::AddUser(Player* const& player) 
{
	currentAccount->users.addAtEnd(player);
}