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
	file.open("data.txt", std::ifstream::in);
	std::string line;
	getline(file, line);

	if (file.is_open()) {
		std::string line;

		while (getline(file, line))
		{


			if (line == "GAME")
			{
				std::string name, text,price, rating, id, likes, dislikes;
				
				getline(file, id);
				getline(file, name);
				getline(file, text);
				getline(file, price);
				getline(file, rating);
				getline(file, likes);
				getline(file, dislikes);


				store.AddGame(new Game(name, text, std::stoi(price), std::stoi(rating),std::stoi(id),std::stoi(likes),std::stoi(dislikes)));
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
				




				accounts[accounts.length() - 1]->AddUser(new Player(name, password, Utils::Stringtodate(date), std::stoi(credit)));
			}

			if (line == "ACCOUNT-ADMIN")
			{
				std::string date, name, password, credit;
				getline(file, date);
				getline(file, name);
				getline(file, password);
				getline(file, credit);
				accounts[accounts.length() - 1]->AddUser(new Admin(name, password, Utils::Stringtodate(date),std::stoi(credit)));

			}


			if (line == "LIBRARY-ITEM")
			{
				std::string number, date,liked,disliked, minutes;
				getline(file, number);
				getline(file, date);
				getline(file, minutes);
				getline(file, liked);
				getline(file, disliked);

				accounts[accounts.length() - 1]->GetUser(accounts[accounts.length() - 1]->GetUserCount() - 1)->AddGame(new LibraryItem(Utils::Stringtodate(date), store.GetGame(std::stoi(number)),std::stoi(liked),std::stoi(disliked),std::stoi(minutes)));
			}
		}
		file.close();
	}

}
void Application::Save() {

	std::ofstream file;
	file.open("data.txt");

	for (int i=0;i<store.GetGameCount();i++)
	{
		Game* game = store.GetGame(i);
		/*getline(file, line);
		getline(file, name);
		getline(file, text);
		getline(file, price);
		getline(file, rating);
		*/
		file << "GAME\n";
		file << i + "\n";
		file << game->GetName() + "\n";
		file << game->GetDescription() + "\n";
		file << game->GetCost() + "\n";
		file << game->getAgeRating() + "\n";


	}

	for (int i = 0; i < accounts.length(); i++)
	{
		Account* acc=accounts[i];
		file << "ACCOUNT\n";
		file << acc->GetSavedData();
		
		for (int y = 0; y < acc->GetUserCount();y++)
		{
			User* user=acc->GetUser(y);
			if (dynamic_cast<Admin*>(user))
			{
				file << "ACCOUNT-ADMIN\n";
			}
			else
			{
				file << "ACCOUNT-PLAYER\n";
			}
			file << user->SavedData();
			file << user->GetCredits()+"\n";
			
			for (int z = 0; z <user->GetLibrarySize(); z++)
			{
				file << "LIBRARY-ITEM\n";
				file << user->GetLibraryItem(z)->GetSavedData();
			}

		}

	}


}