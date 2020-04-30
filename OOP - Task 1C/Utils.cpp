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

bool Utils::WithinRange(const int& cost, const int& lower, const int& upper) {
	return cost >= lower && cost <= upper;
}

std::string Utils::ToUpper(std::string text) {
	for (int i(0); i < text.length(); ++i)
		if (islower(text[i]))
			text[i] = text[i] - 32;
	return text;
}

std::string Utils::ToUpperRec(std::string text) {
	if (!text.length())
		return "";
	return (char)toupper(text[0]) + ToUpperRec(text.substr(1));
}

bool Utils::IsDateBefore(const Date& d1, const Date& d2) {
	return d1 < d2;
}

bool Utils::PurchasedAfter(const LibraryItem* l1 , const LibraryItem* l2) {
	return !IsDateBefore(l1->getDatePurchased(), l2->getDatePurchased());
}

bool Utils::CompareLibraryItemNames(const LibraryItem* l1, const LibraryItem* l2) {
	return l1->game->GetName() < l2->game->GetName();
}