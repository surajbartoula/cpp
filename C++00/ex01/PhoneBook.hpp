/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:17:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/17 14:49:57 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
private:
	Contact contacts[8];
	int		size;
	int		index;
public:
	PhoneBook() : size(0), index(0) {} //initialization list
	int		get_size(void) const;
	void	add_contact(std:: string data[5]);
	void	display_contact(int i) const;
	void	display_phonebook(void) const;
};