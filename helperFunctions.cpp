#include "helperFunctions.hpp"
#include "handleDataType.hpp"

// =========================================================================================
// ==================================   WELCOME MESSAGE   ==================================
// =========================================================================================

void showWelcome() {
	std::cout << "\n\n\033[38;5;70m ____ ---------------------------------------------------------- ____";
	std::cout << "\n\033[38;5;70m ____                                                            ____";
	std::cout << "\n\033[38;5;70m ____    ### Welcome to the easy C++ Template Calculator! ###    ____";
	std::cout << "\n\033[38;5;70m ____           It's pretty much useless in real life. ;)        ____";
	std::cout << "\n\033[38;5;70m ____                          Enjoy!                            ____";
	std::cout << "\n\033[38;5;70m ____                                                            ____";
	std::cout << "\n\033[38;5;70m ____                                                            ____\n";

	std::cout <<  "\t\t\t     __________\n";
	std::cout <<  "\t\t\t    | ________ |\n";
	std::cout <<  "\t\t\t    ||12345678||\n";
	std::cout <<  "\t\t\t    |\"\"\"\"\"\"\"\"\"\"|\n";
	std::cout <<  "\t\t\t    |[M|#|C][-]|\n";
	std::cout <<  "\t\t\t    |[7|8|9][+]|\n";
	std::cout <<  "\t\t\t    |[4|5|6][x]|\n";
	std::cout <<  "\t\t\t    |[1|2|3][%]|\n";
	std::cout <<  "\t\t\t    |[.|O|:][=]|\n";
	std::cout <<  "\t\t\t    \"----------\"\033[0m\n\n";
}

// =========================================================================================
// =================================   MENU (DATA TYPES)   =================================
// =========================================================================================

int showMenu() {
	int menuChoice = 0;

	// show menu until a valid choice is made
	while (true) {
		std::cout << " What type of data will be calculated?\n\n";
		std::cout << " 1. Integer\n";
		std::cout << " 2. Float\n";
		std::cout << " 3. Double\n";
		std::cout << " 4. Exit\n\n";
		std::cout << "\033[38;5;70m Enter your choice: \033[0m";

		if (std::cin >> menuChoice) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
		} else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menuChoice = 0; 
		}

		if (menuChoice >= 1 && menuChoice <= 4) // correct choice
			return menuChoice;

		// if the code reached this point, it means the choice was invalid (either not a number, or out of range)
		clearScreen();
		showWelcome();
		std::cout << "\033[38;5;168m Invalid choice. Please enter a number between 1 and 4.\033[0m\n\n";
	}
}

// =========================================================================================
// =================================   CHOOSE OPERATION   ==================================
// =========================================================================================

int chooseOperation() {
	int operation = 0;

	while (true) {
		std::cout << "\n ------------------------------------------";
		std::cout << "\n   ###    Operations menu:    ###\n";
		std::cout << " ------------------------------------------\n\n";
		std::cout << " 1. ADD\n";
		std::cout << " 2. SUBTRACT\n";
		std::cout << " 3. MULTIPLY\n";
		std::cout << " 4. DIVIDE\n";
		std::cout << " 5. QUIT\n";
		std::cout << " 6. How many programmers does it take to change a lightbulb?\n\n";
		std::cout << "\033[38;5;70m Enter operation number (1-6): \033[0m";

		if (std::cin >> operation)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			operation = -1;	
		}

		if (operation >= 1 && operation <= MAX_OPERATIONS) {
			if (operation == 5) { // QUIT
				std::cout << "\n Goodbye! 😊 \n\n";
				return 0;
			}
			if (operation == 6) { // JOKE
				printASCIIArt();
				return 0;
			}
			return operation; // operation 1-4
		}
		// try again by incorrect choice:
		clearScreen();
		showWelcome();
		std::cout << "\033[38;5;168m\n Invalid choice. Please enter a number between 1 and 6.\033[0m\n";
	}
}

// =========================================================================================
// =================================   ENABLE ANSI (WIN)  ==================================
// =========================================================================================

/*
	Enables ANSI escape sequence support on Windows 10+ consoles
	This allows colored text and cursor positioning using ANSI codes
	No effect on Unix-like systems where ANSI is typically supported by default
*/

void enableANSI() {
	#ifdef _WIN32
		// enable ANSI escape codes in Windows console (from Windows 10)
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return;

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) return;

		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	#endif
}

// =========================================================================================
// ===================================   CLEAR SCREEN   ====================================
// =========================================================================================

void clearScreen() {
	// ANSI - code works on Linux/macOS and Windows 10+ (after enableANSI)
	std::cout << "\033[2J\033[H" << std::flush;
}

// =========================================================================================
// ==================================   ASK TO CONTINUE   ==================================
// =========================================================================================

bool askToContinue() {
	char answer;
	std::cout << " Again? (y/n): ";
	std::cin >> answer;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
	return (answer == 'y' || answer == 'Y');
}
