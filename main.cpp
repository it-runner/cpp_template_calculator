/**
 * @file main.cpp
 * @author it-runner.pl
 * @brief Program to calculate various data types
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 it-runner.pl
 * 
 */

#include "Calculator.hpp"
#include "helperFunctions.hpp"
#include "handleDataType.hpp"

int main() {

	enableANSI(); // enable ANSI escape codes for Windows

	while (true) {
		clearScreen();
		showWelcome(); 																		// ----- print welcome message ------

		int dataType = showMenu();															// ----- choose data type -----

		if (dataType == 4) {
			std::cout << "\n Goodbye! 😊 \n\n";
			break;
		}

		bool continueExecution = true;


		switch (dataType) {																	// ----- choose operation and print result -----
			case 1: continueExecution = handleDataType<int>("integer"); break;
			case 2: continueExecution = handleDataType<float>("float"); break;
			case 3: continueExecution = handleDataType<double>("double"); break;
		}

		/* --------------------------------- CONTINUE OR QUIT --------------------------------- */

		if (!continueExecution)	// checks if any of the handleDataType functions returned false
			break;
		if (!askToContinue()) {	// checks if the user wants to continue
			std::cout << "\n Goodbye! 😊 \n\n";
			break;
		}
	}

	return 0;
}
