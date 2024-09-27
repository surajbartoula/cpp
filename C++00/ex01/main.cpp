/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:13:04 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/26 14:55:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string str;

	while (str != "EXIT")
	{
		std::cout << "\nType ADD, SEARCH or EXIT:" << std::endl;
		std::cout << "\001\033[1;34m\002PhoneBook> \001\033[0;0m\002";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str != "EXIT")
			std::cout << "\033[31m\nPlease provide right command\033[0m" << std::endl;
	}
	return (0);
}
