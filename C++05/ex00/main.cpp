/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:24 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 21:09:51 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat fr = Bureaucrat("france", 150);
		std::cout << fr;
		Bureaucrat pr = Bureaucrat("Paris", 151);
		//Stack unwinding, destructors for all objects in the scope of the try block or any function 
		//on the call stack are automatically called, ensuring proper resource cleanup.
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
