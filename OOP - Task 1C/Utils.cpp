#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

bool Utils::isInteger(const std::string& str) {
	for (auto ch : str) {
		if (ch < 48 || ch > 57)
			return false;
	}
	return true;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::formatCredits(const int& amt) {
	std::stringstream os;
	os << std::fixed << std::setprecision(2) << (amt / 100.0f);
	return os.str();
}