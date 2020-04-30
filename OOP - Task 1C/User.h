#pragma once

#include <string>
#include "Date.h"
#include "List.h"
#include "LibraryItem.h"

class User
{
public:
	User(const std::string&, const std::string&, const Date&);

	virtual LibraryItem* GetLibraryItem(const int&) const = 0;
	virtual int GetLibrarySize() const = 0;
	virtual bool HasGame(const Game*) const = 0;
	virtual bool HasEnoughCredits(const int& amt) const = 0;
	virtual int GetCredits() const = 0;
	virtual void SpendCredits(const int& amt) = 0;
	virtual void AddCredits(const int& amt) = 0;
	virtual void AddGame(LibraryItem* game) = 0;
	const std::string& GetUsername() const;
	const bool CheckDetails(const std::string& username, const std::string& password) const;
	virtual void OrderGamesByDate() = 0;
	virtual void OrderGamesByName() = 0;

private:
	std::string username;
	std::string password;
	Date created;
};