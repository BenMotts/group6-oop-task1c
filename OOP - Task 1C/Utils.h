#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static bool isInteger(const std::string&);
	static std::string formatCredits(const int& amt);
	static std::string ToUpper(std::string);
	static std::string ToUpperRec(std::string);
	static bool StartsWith(const std::string&, const std::string&);
	static bool WithinRange(const int&, const int&, const int&);
    // TODO: 2 versions of ToUpper
};