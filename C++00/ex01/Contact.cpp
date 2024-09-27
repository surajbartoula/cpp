/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:06:57 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::get_fname(void) const
{
	return (this->_fname);
}

std::string Contact::get_lname(void) const
{
	return (this->_lname);
}

std::string Contact::get_nname(void) const
{
	return (this->_nname);
}

std::string Contact::get_pnumber(void) const
{
	return (this->_pnumber);
}

std::string Contact::get_dsecret(void) const
{
	return (this->_dsecret);
}

void Contact::set_fname(std::string str)
{
	this->_fname = str;
}

void Contact::set_lname(std::string str)
{
	this->_lname = str;
}

void Contact::set_nname(std::string str)
{
	this->_nname = str;
}

void Contact::set_pnumber(std::string str)
{
	this->_pnumber = str;
}

void Contact::set_dsecret(std::string str)
{
	this->_dsecret = str;
}
