/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:02:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/13 16:09:49 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::get_firstname() const
{
	return (this->firstname);
}

const std::string& Contact::get_lastname() const
{
	return (this->lastname);
}

const std::string& Contact::get_nickname() const
{
	return (this->nickname);
}

const std::string& Contact::get_secret() const
{
	return (this->secret);
}

const std::string& Contact::get_number() const
{
	return (this->number);
}

void	Contact::set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

void	Contact::set_lastname(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

void	Contact::set_number(std::string number)
{
	this->number = number;
}
