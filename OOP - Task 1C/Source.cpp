#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"

// TODO: Remove from global scope once menu system is integrated
Application app;
void createHardcodedTestData()
{
	// Setup store with some games
	app.GetStore().games[0] = new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5);
	app.GetStore().games[1] = new Game("Braid", "A time twisting puzzle game.", 499, 15);
	app.GetStore().games[2] = new Game("Factorio", "Build a complicated factory in space.", 1599, 12);
	app.GetStore().games[3] = new Game("LIMBO", "Watch out for that spider.", 299, 12);
	app.GetStore().games[4] = new Game("INSIDE", "What are those scientists even doing?!", 1299, 15);
	app.GetStore().games[5] = new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15);
	app.GetStore().games[6] = new Game("Half Life 3", "It's never coming out.", 5999, 18);
	app.GetStore().games[7] = new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18);
	app.GetStore().games[8] = new Game("Brothers", "Split your brain into two thumbs.", 799, 15);

	// Create some users
	Player* u1 = new Admin("Alice", "password", "2018-06-16");
	Player* u2 = new Player("Bob", "password", "2018-09-19");
	Player* u3 = new Player("Charlie", "password", "2018-09-24");

	// With some games in their library
	u1->library[0] = new LibraryItem("2018-06-17", app.GetStore().games[7]);
	u1->library[0] = new LibraryItem("2018-06-18", app.GetStore().games[1]);
	u2->library[0] = new LibraryItem("2018-09-19", app.GetStore().games[2]);
	u2->library[0] = new LibraryItem("2018-09-19", app.GetStore().games[3]);
	u3->library[0] = new LibraryItem("2018-09-24", app.GetStore().games[3]);
	u3->library[0] = new LibraryItem("2018-09-30", app.GetStore().games[6]);

	// Make an account and attach the users
	app.accounts[0] = new Account("alice@shu.com", "password", "2018-06-16");
	//TODO REPLACE PUSH BACK WITH CUSTOM LIST ADDITIONS
	//app.accounts[0]->users[0] = u1;
	//app.accounts[0]->users[1] = u2;
	//app.accounts[0]->users[2] = u3;
	app.accounts[0]->users.push_back(u1);
	app.accounts[0]->users.push_back(u3);
	app.accounts[0]->users.push_back(u2);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

char showGameMenuAndGetUserChoice(Game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->GetName() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->GetDescription() << "\n";
	std::cout << "                                  \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

void gameMenu(Game* game)
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showGameMenuAndGetUserChoice(game);

		switch (choice)
		{
			case 'P': {
				if (app.IsUserLoggedIn())
				{
					// TODO: Implement buying from the store
				}
			} break;
			case 'B': {
				readyToGoBack = true;
			} break;
		}
	}
}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();

	// TODO: app.Load();

	//mainMenu(); // TODO: replace with proper menu system
	MainMenu("MAIN MENU", &app);
	// TODO: app.Save();
}