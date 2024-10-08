/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:38:45 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/25 22:22:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "PhoneBookUtils.hpp"

class PhoneBook
{
private: 
	Contact _contacts[8];
	int		_index;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);
	void	print(Contact contact);
	
	//Getter
	Contact get_contact(int index);

};

#endif