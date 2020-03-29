#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < app->GetStore().GetGameCount(); i++)
	{
		Option(i + 1, app->GetStore().GetGame(i)->GetName());
	}
}

bool StoreMenu::HandleChoice(const char& choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->GetStore().GetGameCount()) {
		Game* gamePointer = app->GetStore().GetGame(index);
		PurchaseGameMenu(gamePointer, gamePointer->GetName(), app);
	}

	return false;
}