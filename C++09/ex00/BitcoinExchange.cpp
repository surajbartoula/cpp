/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:44:44 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/24 18:03:54 by sbartoul         ###   ########.fr       */
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
			try {
				double price = std::stod(priceStr);
				_data[date] = price;
			} catch(const exceptions& e) {
				
			}
		}
	}
}
