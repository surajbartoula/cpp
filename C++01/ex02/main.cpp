/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:37:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/14 21:14:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string string;
	std::string *stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "string address: " << &string << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;
	std::cout << "stringPTR string: " << *stringPTR << std::endl;
	std::cout << "stringREF string: " << stringREF << std::endl;
}
