#include "Application.h"
#include <fstream>
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

void Application::Load() {
	std::ifstream file;
	file.open("data.txt");


	if (file.is_open()) {
		std::string line;




		while (getline(file, line))
		{


			if (line == "GAME")
			{
				std::string name, text;
				std::string price, rating;
				getline(file, line);
				getline(file, name);
				getline(file, text);
				getline(file, price);
				getline(file, rating);

				store.AddGame(new Game(name, text, std::stoi(price), std::stoi(rating)));
			}

			if (line == "ACCOUNT")
			{
				std::string date, email, password;
				getline(file, date);
				getline(file, email);
				getline(file, password);




				AddAccount(new Account(email, password, Utils::Stringtodate(date)));
			}
			if (line == "ACCOUNT-PLAYER")
			{


				std::string date, name, password, credit;
				getline(file, date);
				getline(file, name);
				getline(file, password);
				getline(file, credit);
				getline(file, line);




				accounts[accounts.length() - 1]->AddUser(new Player(name, password, Utils::Stringtodate(date)));
			}

			if (line == "ACCOUNT-ADMIN")
			{
				std::string date, name, password, credit;
				getline(file, date);
				getline(file, name);
				getline(file, password);
				getline(file, credit);
				getline(file, line);
				accounts[accounts.length() - 1]->AddUser(new Admin(name, password, Utils::Stringtodate(date)));

			}


			if (line == "LIBRARY-ITEM")
			{
				std::string number, date, minutes;
				getline(file, number);
				getline(file, date);
				getline(file, minutes);

				accounts[accounts.length() - 1]->GetUser(accounts[accounts.length() - 1]->GetUserCount() - 1)->AddGame(new LibraryItem(Utils::Stringtodate(date), store.GetGame(std::stoi(number))));
			}





		}
	}
}
void Application::Save() {

}