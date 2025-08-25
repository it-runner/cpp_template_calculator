#ifndef handleDataType_HPP
#define handleDataType_HPP

#include <string>

/**
 * @brief Function to handle data type
 * perform arithmetic operations and display the result
 * 
 * @tparam T 
 * @param typeName 
 * @return true 
 * @return false 
 */
template <typename T>
bool handleDataType(const std::string &typeName);

#include "handleDataType.tpp"

#endif
