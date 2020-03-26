#pragma once

#include <string>
#include "Date.h"
#include "List.h"
#include "LibraryItem.h"

class User
{
public:
	User(const std::string&, const std::string&, const Date&);
	virtual ~User();
	virtual LibraryItem* getLibraryItem(const int&) const = 0;
	virtual int getLibrarySize() const = 0;
	const std::string& GetUsername() const;
	const bool CheckDetails(const std::string& username, const std::string& password) const;
private:
	std::string username;
	std::string password;
	Date created; // TODO: replace with custom Date class, currently YYYY-MM-DD
};