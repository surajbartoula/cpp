/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:46 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:25 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string _fname;
	std::string _lname;
	std::string _nname;
	std::string _pnumber;
	std::string _dsecret;
public:
	Contact(void);
	~Contact(void);
	std::string get_fname(void) const;
	std::string get_lname(void) const;
	std::string get_nname(void) const;
	std::string get_pnumber(void) const;
	std::string get_dsecret(void) const;\
	void		set_fname(std::string str);
	void		set_lname(std::string str);
	void		set_nname(std::string str);
	void		set_pnumber(std::string str);
	void		set_dsecret(std::string str);
};

#endif