/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:24:02 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 21:10:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

class ScalarConverter {
public:
	ScalarConverter(void);
	ScalarConverter(const std::string& str);
	ScalarConverter(const ScalarConverter& old);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter(void);

	enum LiteralType {
		CHAR_NORMAL,
		CHAR_ESCAPE,
		CHAR_HEXA,
		CHAR_OCTAL,
		INT,
		FLOAT,
		FLOAT_PSEUDO,
		DOUBLE,
		DOUBLE_PSEUDO,
		ERROR
	};

	class NonDisplayableCharacterException: public std::exception {
		const char *what() const throw();
	};

	class ImpossibleConversionException: public std::exception {
		const char *what() const throw();
	};

	char getChar(void);
	int	getInt(void);
	float getFloat(void);
	double getDouble(void);
private:
	std::string _rawString;
	enum LiteralType _getLiteralType(const std::string& str);
	enum LiteralType _parseCharLiteral(const std::string& str);
	enum LiteralType _parseIntLiteral(const std::string& str);
	enum LiteralType _parseFloatLiteral(const std::string& str);
	enum LiteralType _parseDoubleLiteral(const std::string& str);
	enum LiteralType _inputType;
	bool _isDigit(const char ch);
};

#endif