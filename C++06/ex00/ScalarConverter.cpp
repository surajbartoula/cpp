/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:54:53 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/14 17:53:54 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
: _inputType(ScalarConverter::INT), _rawString("") {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string& rawString)
: _rawString(rawString) {
	_inputType = _getLiteralType(rawString);
	std::cout << "Literal Type: ";
	switch (_inputType)
	{
	case ScalarConverter::CHAR_NORMAL:
		std::cout << "Normal char literal" << std::endl;
		break;
	case ScalarConverter::CHAR_ESCAPE:
		std::cout << "Escape char literal" << std::endl;
		break;
	case ScalarConverter::CHAR_HEXA:
		std::cout << "Hexadecimal char literal" << std::endl;
		break;
	case ScalarConverter::CHAR_OCTAL:
		std::cout << "Octal char literal" << std::endl;
		break;
	case ScalarConverter::INT:
		std::cout << "Int literal" << std::endl;
		break;
	case ScalarConverter::FLOAT:
		std::cout << "Float literal" << std::endl;
		break;
	case ScalarConverter::FLOAT_PSEUDO:
		std::cout << "Float pseudo literal" << std::endl;
		break;
	case ScalarConverter::DOUBLE:
		std::cout << "Double literal" << std::endl;
		break;
	case ScalarConverter::DOUBLE_PSEUDO:
		std::cout << "Double pseudo literal" << std::endl;
		break;
	default:
		throw std::invalid_argument("Invalid input");
		break;
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter& old)
: _inputType(old._inputType), _rawString(old._rawString) {
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs) {
	if (this == &rhs)
		return (*this);
	_inputType = rhs._inputType;
	_rawString = rhs._rawString;
	return (*this);
}

enum ScalarConverter::LiteralType ScalarConverter::_getLiteralType(const std::string& str) {
	if (str[0] == '\'' && str[str.size() - 1] == '\'' && str.size() > 2)
		return (_parseCharLiteral(str));
	if (str.find('.') == std::string::npos && str.find('f') == std::string::npos && str != "nan")
		return (_parseIntLiteral(str));
	//inf->Infinity, nan->Not a number.
	if (str == "-inff" || str == "+inff" || str == "nan" || 
		(str.find("f") != std::string::npos && str != "-inf" && str != "+inf" && str != "nan"))
	{
		return (_parseFloatLiteral(str));
	}
	if (str == "-inf" || str == "+inf" || str == "nan" || (str.find(".") != std::string::npos))
		return (_parseDoubleLiteral(str));
	return (ScalarConverter::ERROR);
}

enum ScalarConverter::LiteralType ScalarConverter::_parseDoubleLiteral(const std::string& str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (ScalarConverter::DOUBLE_PSEUDO);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '+' && str[i] != '-' && _isDigit(str[i]) == false && str[i] != '.')
			return (ScalarConverter::ERROR);
	}
	bool containsNumbers = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (_isDigit(str[i] == true))
			containsNumbers = true;
	}
	if (containsNumbers == false)
		return (ScalarConverter::ERROR);
	size_t dotCount = 0;
	size_t signCount = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '.')
			dotCount++;
		if (str[i] == '+' || str[i] == '-')
			signCount++;
		if (dotCount > 1 || signCount > 1)
			return (ScalarConverter::ERROR);
	}
	return (ScalarConverter::DOUBLE);
}

enum ScalarConverter::LiteralType ScalarConverter::_parseFloatLiteral(const std::string& str) {
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (ScalarConverter::FLOAT_PSEUDO);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '+' && str[i] != '-' && _isDigit(str[i]) == false &&
			str[i] != 'f' && str[i] != '.')
		{
			return (ScalarConverter::ERROR);
		}
	}
	bool containsNumbers = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (_isDigit(str[i]) == true)
			containsNumbers = true;
	}
	if (containsNumbers == false)
		return (ScalarConverter::ERROR);
}

//Pseudo-literals aren't exactly "literals" in the traditional sense(like 42 or "hello").Instead,they represent special,predefined
//language constructs or values that behave like literals but have additional semantics or functionality tied to the language.