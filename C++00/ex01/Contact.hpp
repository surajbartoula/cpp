/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:56:16 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/13 16:02:14 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string secret;
	std::string number;
public:
	const std::string& get_firstname(void) const;
	const std::string& get_lastname(void) const;
	const std::string& get_nickname(void) const;
	const std::string& get_secret(void) const;
	const std::string& get_number(void) const;
	void				set_firstname(std::string firstname);
	void				set_lastname(std::string lastname);
	void				set_nickname(std::string nickname);
	void				set_secret(std::string secret);
	void				set_number(std::string number);
};