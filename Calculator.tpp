#include "Calculator.hpp"

// constructor with initializer list
template <typename T>
Calculator<T>::Calculator(T x, T y) : _x(x), _y(y) {}

// -------------------------------------------------------------------------------------------------------- ADD
template <typename T> 
T Calculator<T>::add() const {
	if ((_x > 0 && _y > std::numeric_limits<T>::max() - _x) ||			// overflow
		(_x < 0 && _y < std::numeric_limits<T>::min() - _x)) {			// underflow
		throw std::overflow_error("Addition would cause overflow");
	}
	return _x + _y;
}

// -------------------------------------------------------------------------------------------------------- SUBTRACT
template <typename T> 
T Calculator<T>::subtract() const {
	if ((_y > 0 && _x < std::numeric_limits<T>::min() + _y) ||			// underflow
		(_y < 0 && _x > std::numeric_limits<T>::max() + _y)) {			// overflow
		throw std::overflow_error("Subtraction would cause overflow");
	}
	return _x - _y;
}

// -------------------------------------------------------------------------------------------------------- MULTIPLY

template <typename T>
T Calculator<T>::multiply() const {
	if (_x == 0 || _y == 0)
		return 0;

	T result = _x * _y;
	/*
		if division of the result by one of the factors doesn't give the other factor
		it means that there was an overflow or underflow, it works for all combinations of signs
	*/
	if (std::numeric_limits<T>::is_integer) {
		if (_x != 0 && result / _x != _y) {
			throw std::overflow_error("Multiplication would cause overflow");
		}
	}
	// for float/double INF/NaN are supported by the processor
	return result;
}


// -------------------------------------------------------------------------------------------------------- DIVIDE
template <typename T>
T Calculator<T>::divide() const {
	// check special cases only for integer types
	if (std::numeric_limits<T>::is_integer) {
		if (_y == 0) {
			throw std::runtime_error("Division by zero");
		}
		// check for overflow for INT_MIN / -1
		if (std::numeric_limits<T>::is_signed &&
			_x == std::numeric_limits<T>::min() && _y == -1) {
			throw std::overflow_error("Division would cause overflow");
		}
	}
	// for float/double INF/NaN are supported by the processor
	return _x / _y;
}
