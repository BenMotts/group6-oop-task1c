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

bool Utils::StartsWith(const std::string& fullText, const std::string& searchText) {
	for (int i(0); i < searchText.length(); ++i) {
		if (toupper(fullText[i]) != toupper(searchText[i]))
			return false;
	}
	return true;
}

bool Utils::WithinRange(const int& cost, const int& upper, const int& lower) {
	return cost >= lower && cost <= upper;
}

std::string Utils::ToUpper(std::string text) {
	for (int i(0); i < text.length(); ++i)
		if (islower(text[i]))
			text[i] = text[i] - 32;
	return text;
}

//TODO does not work properly, come back to fix
std::string Utils::ToUpperRec(std::string text) {
	if (!text.length())
		return text;
	if (islower(text[0])) {
		return (char)toupper(text[0]) + ToUpperRec(text.substr(1));
	}
	return ToUpperRec(text.substr(1));
}