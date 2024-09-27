/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:39:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/25 14:41:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

std::string add_spaces(int n);
std::string fix_width(std::string str, long unsigned max);

int	display_phonebook(Contact contacts[8]);

#endif