/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:05 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/27 09:31:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define b_bright "\001\033[1;34m\002"
#define b_bright_a "\001\033[0;0m\002"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	std::cout << "\001\033[1;34m\002\nWelcome to your new contact manager.\001\033[0;0m\002"<< std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\001\033[1;34m\002\nSee you soon!.\001\033[0;0m\002" << std::endl;
}

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

void	PhoneBook::add(void)
{
	std::string str;
	str = "";
	if (this->_index > 7)
		std::cout << "\033[31mWarning overwriting the \033[0m" << this->_contacts[this->_index % 8].get_fname() << std::endl;
	while (!std::cin.eof() && (str == "" || is_empty(str)))
	{
		std::cout << b_bright << "First Name: " << b_bright_a;
		std::getline(std::cin, str);
		if (!str.empty() && !is_empty(str))
			this->_contacts[this->_index % 8].set_fname(str);
		else
			std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
	}
	str = "";
	while (!std::cin.eof() && (str == "" || is_empty(str)))
	{
		std::cout << b_bright << "Last Name: " << b_bright_a;
		std::getline(std::cin, str);
		if (!str.empty() && !is_empty(str))
			this->_contacts[this->_index % 8].set_lname(str);
		else
			std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
	}
	str = "";
	while (!std::cin.eof() && (str == "" || is_empty(str)))
	{
		std::cout << b_bright << "NickName: " << b_bright_a;
		std::getline(std::cin, str);
		if (!str.empty() && !is_empty(str))
			this->_contacts[this->_index % 8].set_nname(str);
		else
			std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
	}
	str = "";
	while (!std::cin.eof() && (str == "" || !is_valid_number(str)))
	{
		std::cout << b_bright << "Phone Number: " << b_bright_a;
		std::getline(std::cin, str);
		if (!(is_valid_number(str)))
			std::cout << "\033[31mPlease input a valid number\033[0m" << std::endl;
		else if (!str.empty() && !is_empty(str))
			this->_contacts[this->_index % 8].set_pnumber(str);
	}
	str = "";
	while (!std::cin.eof() && (str == "" || is_empty(str)))
	{
		std::cout << b_bright << "Darkest Secret: " << b_bright_a;
		std::getline(std::cin, str);
		if (!str.empty() && !is_empty(str))
		{
			this->_contacts[this->_index % 8].set_dsecret(str);
			std::cout << "\001\033[0;32m\002\nContact Added Successfully!\001\033[0m\002" << std::endl;
		}
		else
			std::cout << "\033[31mField cannot be empty!\033[0m" << std::endl;
	}
	this->_index++;
}

void	PhoneBook::print(Contact contact)
{
	if (!contact.get_fname().size())
	{
		std::cout << "\033[31m\nNo data inserted. Please add some Contact first.\033[0m" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright_a << std::endl;
	std::cout << b_bright << "|  Contact information for specified index  |" << b_bright_a << std::endl;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright_a << std::endl;
	
	std::cout << b_bright << "First Name: " << contact.get_fname() << b_bright_a << std::endl;
	std::cout << b_bright << "Last Name: " << contact.get_lname() << b_bright_a << std::endl;
	std::cout << b_bright << "Nickname: " << contact.get_nname() << b_bright_a << std::endl;
	std::cout << b_bright << "Number: " << contact.get_pnumber() << b_bright_a << std::endl;
	std::cout << b_bright << "Darkest Secret: " << contact.get_dsecret() << b_bright_a << std::endl;
}

Contact PhoneBook::get_contact(int index)
{
	return (this->_contacts[index % 8]);
}

void	PhoneBook::search(void)
{
	std::string str;

	if (!display_phonebook(this->_contacts))
	{
		std::cout << std::endl << b_bright << "PhoneBook is empty!" << b_bright_a << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << b_bright << "Select an index: " << b_bright_a;
		if (std::getline(std::cin, str) && str!= "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contacts[str[0] - 1 - '0'].get_fname().size())
				break;
		}
		if (str != "")
			std::cout << "Invalid Index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}
