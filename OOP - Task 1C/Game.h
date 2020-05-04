#pragma once

#include <string>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int,const int&,int,int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		std::string PrintRating() const;
		int GetCost() const;
		int getLikeRating() const;
		int getAgeRating() const;
		void likeGame();
		void dislikeGame();
		void removeLike();
		void removeDislike();
		int GetGameID()const;

	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int likes;
		int dislikes;
		int GameID;
		
};