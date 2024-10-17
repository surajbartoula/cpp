/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:19:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/17 14:08:18 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Harl {
	public:
		void complain(std::string level);
		enum LogType
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			INVALID,
		};
		static LogType strToLogType(const std::string &str);
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