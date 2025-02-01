/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchane.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:44:55 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/25 18:53:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, double> _data;
	std::string findClosestDate(const std::string& date) const;
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string& databaseFile);
	BitcoinExchange(const BitcoinExchange& old);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();
	bool isValidDate(const std::string& date) const;
	double getPriceForDate(const std::string& date) const;
};

void processInputFile(const std::string& inputFile, const BitcoinExchange& btc);

#endif