/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchane.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:44:55 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/24 11:24:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, double> _data;
	bool isValidDate(const std::string& date) const;
	std::string findClosestDate(const std::string& date) const;
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string& databaseFile);
	BitcoinExchange(const BitcoinExchange& old);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();
	double getPriceForDate(const std::string& date) const;
};

#endif