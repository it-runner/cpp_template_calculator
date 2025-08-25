#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

enum {MAX_OPERATIONS = 6};
enum {MAX_DATA_TYPES = 4};

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <stdexcept>
#include <limits>
#include <iomanip>
#include "helperFunctions.hpp"

/**
 * @brief Class representing a calculator for various data types (int, float, double)
 * allowing to perform basic arithmetic operations (+, -, *, /)
 * 
 * @tparam T - data type
 */
template <typename T>
class Calculator {
	private:
		T _x;								// operand 1
		T _y;								// operand 2

	public:
		Calculator(T x, T y); 				// constructor

		T add() const;	
		T subtract() const;
		T multiply() const;
		T divide() const;

};

#include "Calculator.tpp"

#endif
