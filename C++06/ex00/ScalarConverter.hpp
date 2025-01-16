/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:24:02 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 13:03:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& old);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter(void);

	static bool isChar(const std::string& input);
	static bool isInt(const std::string& input);
	static bool isFloat(const std::string& input);
	static bool isDouble(const std::string& input);

	static void printChar(const std::string& input);
	static void printInt(const std::string& input);
	static void printFloat(const std::string& input);
	static void printDouble(const std::string& input);

public:
	static void convert(const std::string& input);
};

#endif

// ex00: Introduction to static casting and conversion of scalar types
// ex01: Serialization and reinterpret casting
// ex02: Identification of real types of classes via dynamic casting