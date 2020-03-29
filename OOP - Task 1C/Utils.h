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
    // TODO: 2 versions of ToUpper
};