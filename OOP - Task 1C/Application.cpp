#include "Application.h"
#include <fstream>
using namespace std;
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
	Application app;
	int counter = 0, build = 0, object = 0;
	fstream file;
	string filename = "account.txt";
	string game, text, price, rating, word;
	string player, name, password, memory;
	file.open(filename.c_str());
	while (file >> word)
	{
		build = 0;
		counter++;

		if (counter == 1)
		{
			player = word;
		}

		if (counter == 2)
		{
			name = word;
		}

		if (counter == 3)
		{
			password = word;
			counter = 0;
			build = 1;
		}

		if (build == 1)
		{
			if (player == "Player")
			{
				if (object == 0)
				{
					Player* u2 = new Player(name, password, Date());
					object++;
				}
				if (object == 1)
				{
					Player* u3 = new Player(name, password, Date());
				}
			}
			if (player == "Admin")
			{
				Player* u1 = new Admin(name, password, Date());
			}
		}

	}
	file.close();
	filename = "user.txt";
	file.open(filename.c_str());
	counter = 0;
	while (file >> word)
	{
		if (counter == 0)
		{
			name = word;
		}
		if (counter == 1)
		{
			password = word;
			app.AddAccount(new Account(name, password, Date()));
			app.LoginAccount(name, password);
			app.GetCurrentAccount()->AddUser(u1);
			app.GetCurrentAccount()->AddUser(u2);
			app.GetCurrentAccount()->AddUser(u3);
			app.LogoutAccount();
		}
		counter++;

	}


}
void Application::Save() {

}