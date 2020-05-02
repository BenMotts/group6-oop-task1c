#pragma once

#include <string>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		int getLikeRating() const;
		void likeGame();
		void dislikeGame();
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int likes;
		int dislikes;
};