#pragma once

#include "Utils.h"
#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
		~LibraryItem();
		const Date& getDatePurchased() const;
		Game* game;
		bool hasLiked() const;
		bool hasDisliked() const;
		void like();
		void dislike();
		std::string getName() const;
		std::string getDesc() const;
		std::string PrintRating() const;

		void playGame();

		std::string GetTimePlayed() const;

	private:
		const Date purchased;
		bool liked;
		bool disliked;
		int minutesPlayed;
};