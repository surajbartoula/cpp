/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:16:23 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/13 23:04:44 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define b_bright "\001\033[1;34m\002"

void	print_name(std::string str)
{
	unsigned int i = 0;

	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		while (i++ < 10 - str.length())
			std::cout << " ";
		std::cout <<str;
	}
}

int	PhoneBook::get_size() const
{
	return (this->size);
}

void	PhoneBook::add_contact(std::string data[5])
{
	int	index;

	index = this->index;
	this->contacts[index].set_firstname(data[0]);
	this->contacts[index].set_lastname(data[1]);
	this->contacts[index].set_nickname(data[2]);
	this->contacts[index].set_number(data[3]);
	this->contacts[index].set_secret(data[4]);
	this->index = (index + 1) % 8;

	if (this->size < 8)
		this->size++;
}

void	PhoneBook::display_contact(int i) const
{
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright << std::endl;
	std::cout << b_bright << "|  Contact information for specified index  |" << b_bright << std::endl;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright << std::endl;
	
	std::cout << "First Name: " << this->contacts[i].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[i].get_lastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
	std::cout << "Number: " << this->contacts[i].get_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i].get_secret() << std::endl;
}

void	PhoneBook::display_phonebook() const
{
	int	i;
	
	i = 0;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright << std::endl;
	std::cout << b_bright << "|     index|first name| last name|  nickname|" << b_bright << std::endl;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright << std::endl;
	while (i < this->size)
	{
		std::cout << b_bright << "|         " << b_bright;
		std::cout << i;
		std::cout << b_bright << "|" << b_bright;
		print_name(this->contacts[i].get_firstname());
		std::cout << b_bright << "|" << b_bright;
		print_name(this->contacts[i].get_lastname());
		std::cout << b_bright << "|" << b_bright;
		print_name(this->contacts[i].get_nickname());
		std::cout << b_bright << "|" << b_bright << std::endl;
		i++;
	}
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright << std::endl;
}
