/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:06:27 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/16 23:13:26 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class Harl {
public:
	void complain(std::string level);

private:
	typedef void (Harl::*log_func)(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void invalidArg(void);
	static std::string states[4];
	static log_func funcs[5];
	static log_func strToLogFunc(const std::string &str);
};
#endif