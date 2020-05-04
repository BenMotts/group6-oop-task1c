#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*,bool,bool,int);
		LibraryItem(const Date&, Game*);
		~LibraryItem();
		const Date& getDatePurchased() const;
		bool hasLiked() const;
		bool isGame(const Game*) const;
		bool hasDisliked() const;
		void like();
		void dislike();
		std::string getName() const;
		std::string getDesc() const;
		std::string PrintRating() const;
		std::string GetSaveData() const;

		void playGame();

		std::string GetTimePlayed() const;

	private:
		const Date purchased;
		bool liked;
		bool disliked;
		int minutesPlayed;
		Game* game;
};