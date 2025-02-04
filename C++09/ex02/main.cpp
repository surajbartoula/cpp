/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:21:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/04 17:20:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe + numbers to sort" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		char *end;
		long nbr = strtol(argv[i], &end, 10);
		if (nbr > INT_MAX || nbr < 0 || errno == ERANGE || *end != '\0' || end == argv[i])
		{
			std::cout << "Error: Please provide positive integer sequence as argument." << std::endl;
			return 1;
		}
	}
	PmergeMe pm;
	pm.fill(argc, argv);
	pm.sort();

	return 0;
}
