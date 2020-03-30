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
void createHardcodedTestData(Application &app)
{
	// Setup store with some games
	app.GetStore().AddGame(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().AddGame(new Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().AddGame(new Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().AddGame(new Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().AddGame(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().AddGame(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().AddGame(new Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().AddGame(new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	app.GetStore().AddGame(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", Date());
	Player* u2 = new Player("Bob", "password",  Date());
	Player* u3 = new Player("Charlie", "password", Date());

	// With some games in their library
	u1->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(7)));
	u1->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(1)));
	u2->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(2)));
	u2->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(3)));
	u3->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(3)));
	u3->AddGame(new LibraryItem(Date(), app.GetStore().GetGame(6)));

	// Make an account and attach the users
	app.AddAccount(new Account("alice@shu.com", "password", Date()));
	app.LoginAccount("alice@shu.com", "password");
	app.GetCurrentAccount()->AddUser(u1);
	app.GetCurrentAccount()->AddUser(u2);
	app.GetCurrentAccount()->AddUser(u3);
	app.LogoutAccount();
}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	Application app;
	createHardcodedTestData(app);

	// TODO: app.Load();

	//mainMenu(); // TODO: replace with proper menu system
	MainMenu("MAIN MENU", &app);

	// TODO: app.Save();
}