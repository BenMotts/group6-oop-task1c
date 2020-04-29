#pragma once

#include <string>
#include "User.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		void AddGame(LibraryItem*) override;
		LibraryItem* GetLibraryItem(const int& index) const override;
		int GetLibrarySize() const override;
		bool HasGame(const Game* game) const override;
		bool HasEnoughCredits(const int& amt) const override;
		int GetCredits() const override;
		void SpendCredits(const int& amt) override;
		void AddCredits(const int& amt) override;

		bool isPlaying(const Game* game);

	private:
		List<LibraryItem*> library;
		int credits;
};