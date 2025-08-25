#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include "Calculator.hpp"
#include "printASCIIArt.hpp"

void	showWelcome();			// shows welcome message
int		showMenu();				// shows menu (data types)
int		chooseOperation();		// chooses operation
void	enableANSI();			// enables ANSI escape codes for Windows
void	clearScreen();			// clears screen
bool	askToContinue();		// asks user to continue

#endif
