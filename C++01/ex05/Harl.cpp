/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:31:16 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/18 12:47:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			<<  std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be "
				"asking for more!"
			<< std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."  << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" <<std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::invalidArg(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::log_func Harl::strToLogFunc(const std::string &str) {
	for (size_t i = 0; i < 4; i++) {
		if (states[i] == str)
			return (Harl::funcs[i]);
	}
	return (Harl::funcs[4]);
}

void Harl::complain(std::string level) {
	log_func func = Harl::strToLogFunc(level);
//log_func is a typedef(alias) for a member function pointer of harl class.
	(this->*func)(); //Calling member functions with pointers
	std::cout << std::endl;
}

std::string Harl::states[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//Static array of string belonging to Harl class
Harl::log_func Harl::funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalidArg};
