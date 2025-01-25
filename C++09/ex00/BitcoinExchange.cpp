/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:44:44 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/25 12:41:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchane.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
	std::ifstream file(databaseFile);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	//getline reads from standard input(std::cin) or streams like std::istringstream.
	//std::istream& getline(std::istream& is, std::string& str, char delim);
	while (std::getline(file, line)) {
		std::istringstream ss(line); //input stringstream
		//Used to treat string as if it were a stream, like a file or input.
		//This allows us to perform formatted input operations(>>, std::getline) etc. (e.g., breaking it into tokens)
		std::string date, priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
			//std::string::npos is a special constant value in C++ that is used to indicate "not found" when performing string operations like searching for substrings
			if (date.find("date") != std::string::npos)
				continue;
			try {
				double price = std::stod(priceStr);
				_data[date] = price;
			} catch(const std::invalid_argument& e) {
				std::cout << "Invalid argument: " << e.what() << std::endl;
			} catch(const std::out_of_range& e) {
				std::cout << "The value is out of range: " << e.what() << std::endl;
			}
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& old): _data(old._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)
		_data = rhs._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29: 28))
			return false;
	}
	return true;
}

//to access key of map it->first and to access value it->second
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
	if (it == _data.end() || it->first != date) {
		if (it == _data.begin())
			return "";
		--it;
	}
	return it->first;
}

double BitcoinExchange::getPriceForDate(const std::string& date) const {
	std::string closestDate = findClosestDate(date);
	if (closestDate.empty())
		throw std::runtime_error("Error: no valid date found for " + date);
	return _data.at(closestDate);
}

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of("\t");
	size_t last = str.find_last_not_of("\t");
	return (first == std::string::npos || last == std::string::npos ? "" : str.substr(first, last - first + 1));
}

void processInputFile(const std::string& inputFile, const BitcoinExchange& btc) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date = trim(date);
			valueStr = trim(valueStr);
			if (date.find("date") != std::string::npos)
				continue;
			double value;
			try {
				char* endPtr;
				value = std::strtod(valueStr.c_str(), &endPtr);
				if (*endPtr != '\0') {
					throw std::invalid_argument("Invalid numeric value: " + valueStr);
				}
			} catch (...) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			} else if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			try {
				double btcPrice = btc.getPriceForDate(date);
				std::cout << date << " => " << valueStr << " = " << (value * btcPrice) << std::endl;
			} catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}
