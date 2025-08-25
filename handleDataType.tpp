#include "Calculator.hpp"

template <typename T>
bool handleDataType(const std::string &typeName) {

	int operationNum = chooseOperation();
	if (operationNum == 0)						// QUIT (5) or JOKE (6) in chooseOperation return 0
		return false;

	T value1, value2, result;
	char sign = '\0';

	// -------------------------------------------------------------------------------------------------------- read first value
	while (true) {
		std::cout << "\033[38;5;70m Enter the first " + typeName + ": \033[0m";
		if (std::cin >> value1) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// clear buffer
			break;
		}
		// if input is incorrect, print the prompt again
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[38;5;168m\n Invalid input! Please enter a valid number.\033[0m\n\n";
	}

	// -------------------------------------------------------------------------------------------------------- read second value
	while (true) {
		std::cout << "\033[38;5;70m Enter the second " + typeName + ": \033[0m";
		if (std::cin >> value2) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[38;5;168m\n Invalid input! Please enter a valid number.\033[0m\n\n";
	}

	// -------------------------------------------------------------------------------------------------------- calculate and print
	/**
	 * @brief Object of Calculator class
	 * 
	 * @param value1
	 * @param value2
	 * 
	 * @return Calculator<T> 
	 */
	Calculator<T> calculator(value1, value2);
	try {
		switch (operationNum) {
			case 1: result = calculator.add(); sign = '+'; std::cout << "\033[38;5;223m\n\tAddition\033[0m\n"; break;
			case 2: result = calculator.subtract(); sign = '-'; std::cout << "\033[38;5;223m\n\tSubtraction\033[0m\n"; break;
			case 3: result = calculator.multiply(); sign = '*'; std::cout << "\033[38;5;223m\n\tMultiplication\033[0m\n"; break;
			case 4: result = calculator.divide(); sign = '/'; std::cout << "\033[38;5;223m\n\tDivision\033[0m\n"; break;
		}
		std::cout << " \033[38;5;223m---- \n\n";
		if (std::numeric_limits<T>::is_integer)
			std::cout << std::noshowpoint;
		else
			std::cout << std::fixed << std::setprecision(6);
		if (value2 < 0) {	// print negative second value in parentheses for better readability
			std::cout << "\t\t" << value1 << " " << sign << " (" << value2 << ") = " << result << "\n\n";
		} else {
			std::cout << "\t\t" << value1 << " " << sign << " " << value2 << " = " << result << "\n\n";
		}
		std::cout << " ---- \033[0m\n\n";
	} catch (const std::exception &e) {
		std::cout << "\033[38;5;168m Error: " << e.what() << "\033[0m\n\n"; // print error message when input is incorrect
	}

	return true;
}
