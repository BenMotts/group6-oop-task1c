#pragma once
//test comment
#include "Utils.h"
#include "Application.h"

#include <iostream>
#include <string>

// Base class for UI pages
class Menu
{
public:
	Menu(const std::string& title, Application* app);

	void Paint();

	// Use this function to output all the options specific to your menu
	virtual void OutputOptions() = 0;

	// Use this function to handle the possible choices from your menu
	// Returning true means you are ready to go back to the previous menu
	// Returning false means you will stay on the same menu
	virtual bool HandleChoice(const char&) = 0;

protected:
	Application *app;

	void Line();										// output blank line
	void Line(const std::string& text);					// output message
	void Option(int id, const std::string& option);		// output menu option
	void Option(char id, const std::string& option);	// output menu option
	std::string Question(const std::string& question);	// output question and return the user's input
	void BlockingMessage(const std::string& message);	// output message and wait for the user to press enter
	void PrintLine(const std::string& message);			// output simple message as single line
	bool DoubleCheckQuestion() const;					// output a Y/N check question

private:
	std::string title_;

	void Header();
	void Footer();
};