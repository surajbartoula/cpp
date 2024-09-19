/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:22:34 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/19 23:03:38 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int is_empty(std::string& number)
{
	std::string::size_type i = 0;

	while (i < number.length())
	{
		if (number[i] != ' ' && number[i] != '\n' && number[i] != '\t')
			return 0;
		i++;
	}
	return 1;
}

static int is_spaces(std::string number)
{
	int i = 0;

	while (number[i])
	{
		if (number[i] != ' ')
			return 0;
		i++;
	}
	return 1;
}

static int	is_valid_number(std::string number)
{
	int i = 0;

	if (is_spaces(number))
		return 0;
	while (number[i])
	{
		if (number[i] == ' ')
		{
			i++;
			continue;
		}
		if (number[i] < '0' || number[i] > '9')
			return 0;
		i++;
	}
	return (1);
}

int main()
{
	PhoneBook phonebook;
	std::string data[5];
	std::string input;
	int			index;

	std::cout << "\001\033[1;34m\002\nWelcome to your new contact manager.\001\033[0;0m\002"<< std::endl;
	while (1)
	{
		std::cout << "\nType ADD, SEARCH or EXIT:" << std::endl;
		std::cout << "\001\033[1;34m\002PhoneBook> \001\033[0;0m\002";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input == "ADD")
		{
			std::cout << "\001\033[1;34m\002\nEnter Contact Information\001\033[0;0m\002" << std::endl;
			do {
				std::cout << "First Name: ";
				std::getline(std::cin, data[0]);
				if (std::cin.eof())
					break;
				if (!is_empty(data[0]))
					break;
				std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
			} while (is_empty(data[0]));
			do {
				std::cout << "Last Name: ";
				std::getline(std::cin, data[1]);
				if (std::cin.eof())
					break;
				if (!is_empty(data[1]))
					break;
				std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
			} while (is_empty(data[1]));
			do {
				std::cout << "NickName: ";
				std::getline(std::cin, data[2]);
				if (std::cin.eof())
					break;
				if (!is_empty(data[2]))
					break;
				std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
			} while (is_empty(data[2]));
			do {
				std::cout << "Phone Number: ";
				std::getline(std::cin, data[3]);
				if (std::cin.eof())
					break;
				if (is_valid_number(data[3]))
					break;
				std::cout << "Please input a valid number" << std::endl;
			} while (!is_valid_number(data[3]));
			do {
				std::cout << "Darkest Secret: ";
				std::getline(std::cin, data[4]);
				if (std::cin.eof())
					break;
				if (!is_empty(data[4]))
					break;
				std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
			} while (is_empty(data[4]));
			phonebook.add_contact(data);
			std::cout << "\001\033[0;32m\002Contact Added Successfully!\001\033[0;32m\002" << std::endl;
		}
		else if (input == "SEARCH")
		{
			if (input == "SEARCH" && phonebook.get_size() == 0)
			{
				std::cout << "\033[31m\nNo data inserted. Please add some Contact first.\033[0m" << std::endl;
				phonebook.display_phonebook();
				continue;
			}
			phonebook.display_phonebook();
			std::cout << "\nInsert Index: ";
			std::cin >> index;
			if (std::cin.fail() || index < 0 || index >= phonebook.get_size())
			{
				std::cout << "Invalid Index!" << std::endl;
				std::cin.clear();
				std::getline(std::cin, input);
				continue;
			}
			phonebook.display_contact(index);
			std::cin.clear();
			std::getline(std::cin, input);
			continue;
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Please provide right command" << std::endl;
	}
}
