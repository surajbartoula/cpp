/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/25 17:47:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookUtils.hpp"

#define b_bright "\001\033[1;34m\002"
#define b_bright_a "\001\033[0;0m\002"

std::string fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int display_phonebook(Contact contacts[8])
{
	std::string str;
	char		c;
	int			i;

	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright_a << std::endl;
	std::cout << b_bright << "|     index|first name| last name|  nickname|" << b_bright_a << std::endl;
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright_a << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1  - '0'].get_fname().size() && ++i)
		{
			str = c;
			str = fix_width(str, 10);
			std::cout << b_bright << "|" << std::setw(10) << std::right << str << b_bright_a;
			str = fix_width(contacts[c - 1 - '0'].get_fname(), 10);
			std::cout << b_bright << "|" << std::setw(10) << std::right << str << b_bright_a;
			str = fix_width(contacts[c - 1 - '0'].get_lname(), 10);
			std::cout << b_bright << "|" << std::setw(10) << std::right << str << b_bright_a;
			str = fix_width(contacts[c - 1 - '0'].get_nname(), 10);
			std::cout << b_bright << "|" << std::setw(10) << std::right << str << b_bright_a;
			std::cout << b_bright <<"|" << b_bright << std::endl;
		}
	}
	std::cout << b_bright << "+----------+----------+----------+----------+" << b_bright_a << std::endl;
	return (i);
}
