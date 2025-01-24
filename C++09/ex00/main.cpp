/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:44:27 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/23 22:44:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchane.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file.";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Erro: could not open file.";
		return 1;
	}
}
