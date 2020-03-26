#pragma once

#include <string>
#include "User.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		void addGame(LibraryItem*);
		LibraryItem* getLibraryItem(const int& index) const final;
		int getLibrarySize() const final;
	private:
		List<LibraryItem*> library;
};