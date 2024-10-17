/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:27:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/17 14:09:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void harlFilter(const std::string &filter)
{
	Harl harl;

	switch (Harl::strToLogType(filter))
	{
	case Harl::DEBUG:
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case Harl::INFO:
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case Harl::WARNING:
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case Harl::ERROR:
		harl.complain("ERROR");
		break;
	default:
		harl.complain("INVALID");
		std::exit(EXIT_FAILURE);
	}
	std::exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	harlFilter(argv[1]);
}