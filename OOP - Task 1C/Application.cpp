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
//currentAccount = accounts[0];
//return false;
	for (int i(0); i < accounts.length(); ++i) {
		if (accounts[i]->CheckDetails(email, password)) {
			currentAccount = accounts[i];
			return false;
		}
	}
	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: Update to algorythm to speed up login/decrease code amount
	for (int i(0); i < currentAccount->GetUserCount(); ++i) {
		if (currentAccount->GetUser(i)->CheckDetails(username, password)) {
			currentUser = currentAccount->GetUser(i);
			return true;
		}
	}
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogoutAccount() {
	currentUser = nullptr;
	currentAccount = nullptr;
}

void Application::AddAccount(Account* const& acc) {
	accounts.addAtEnd(acc);
}

int Application::GetAccountCount() const {
	return accounts.length();
}