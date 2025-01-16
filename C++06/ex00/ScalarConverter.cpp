/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:54:53 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 22:41:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& old) {
	std::cout << "Copy constructor called." << std::endl;
	(void)old;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	std::cout << "Copy assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}
ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called." << std::endl;
}

bool ScalarConverter::isChar(const std::string& input) {
	return input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]);
	//isprint and isdigit are designed to work on a single character, not on an entire string.
}

bool ScalarConverter::isInt(const std::string& input) {
    char *end;
    long int value = std::strtol(input.c_str(), &end, 10); //strtol converts string to a long int.
	//long int strtol(const char* str, char** endptr, int base);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& input) {
    char *end;
    std::strtof(input.c_str(), &end);
	//float std::strtof(const char* str, char** endptr);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& input) {
    char *end;
    std::strtod(input.c_str(), &end);
	//double std::strtod(const char* str, char** endptr);
    return *end == '\0';
}

void ScalarConverter::printChar(const std::string& input) {
    char c = input[0];

    std::cout << "char: " << c << "\n"
              << "int: " << static_cast<int>(c) << "\n"
              << "float: " << static_cast<float>(c) << ".0f\n"
              << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::printInt(const std::string& input) {
    long int value = std::strtol(input.c_str(), NULL, 10);

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }
	//Safe to convert form long int to int because already verified that it's within the valid int range
    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (intValue < 32 || intValue > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << charValue << "\n";

    std::cout << "int: " << intValue << "\n"
              << "float: " << static_cast<float>(intValue) << ".0f\n"
              << "double: " << static_cast<double>(intValue) << ".0\n";
}

void ScalarConverter::printFloat(const std::string& input) {
    float value = std::strtof(input.c_str(), NULL);
	//errno is a global variable that is used to indicate error conditions
	//If the conversion fails, std::strtof sets errno to ERANGE,
	//ERANGE: Result out of range (e.g., when a number is too large to fit into the requested type).
    if (errno == ERANGE)
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
    }
    else
    {
        if (intValue < 32 || intValue > 126)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << charValue << "\n";

        std::cout << "int: " << intValue << "\n";
    }
	float fractionalPart = value - static_cast<int>(value);
	int count = 0;
	while (fractionalPart != 0 && count < 15) {
		fractionalPart *= 10;
		fractionalPart -= static_cast<int>(fractionalPart);
		count++;
	}
	if (count > 1) {		
		std::ostringstream oss;
		//Without std::fixed, 12345.6789 could be displayed as 1.234568e+04 in scientific notation.
		// setprecision specifies how many digits should be displayed after the decimal point.
		oss << std::fixed << std::setprecision(15) << value;
		//retrieves the string from the ostringstream (oss) which contains the formatted floating-point value
		std::string str = oss.str();
		size_t dotPos = str.find('.');
		if (dotPos != std::string::npos) {
			//find the position where the last character in the string is not character '0'
			size_t lastNonZero = str.find_last_not_of('0');
			if (lastNonZero != std::string::npos && lastNonZero > dotPos)
				str.erase(lastNonZero + 1);
			else
				str.erase(dotPos + 2);
		}
		std::cout << "float: " << value << "f\n"
					<< "double: " << static_cast<double>(value) << "\n";
	}
	else {
		std::cout << std::fixed << std::setprecision(1)
				  << "float: " << value << "f\n"
				  << "double: " << static_cast<double>(value) << "\n";
	}
}

void ScalarConverter::printDouble(const std::string& input) {
    double value = std::strtod(input.c_str(), NULL);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
    }
    else
    {
        if (intValue < 32 || intValue > 126)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << charValue << "\n";

        std::cout << "int: " << intValue << "\n";
    }
	double fractionalPart = value - static_cast<int>(value);
	int count = 0;
	while (fractionalPart != 0 && count < 15) {
		fractionalPart *= 10;
		fractionalPart -= static_cast<int>(fractionalPart);
		count++;
	}
	if (count > 1)
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(15) << value;
		std::string str = oss.str();
		size_t dotPos = str.find('.');
		if (dotPos != std::string::npos) {
			size_t lastNonZero = str.find_last_not_of('0');
			if (lastNonZero != std::string::npos && lastNonZero > dotPos)
				str.erase(lastNonZero + 1);
			else
				str.erase(dotPos + 2);
		}
		std::cout << "float: " << static_cast<float>(value) << "f\n"
				<< "double: " << value << "\n";
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1)
        		  << "float: " << static_cast<float>(value) << "f\n"
            	  << "double: " << value << "\n";
	}
}

void ScalarConverter::convert(const std::string& input) {
	if (isChar(input))
		printChar(input);
	else if (isInt(input))
		printInt(input);
	else if (isFloat(input))
		printFloat(input);
	else if (isDouble(input))
		printDouble(input);
	else if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
	}
	else if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input + 'f' << std::endl;
		std::cout << "double: " << input << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
}

//Pseudo-literals aren't exactly "literals" in the traditional sense(like 42 or "hello")
//.Instead,they represent special,predefined language constructs or values that behave 
//like literals but have additional semantics or functionality tied to the language.