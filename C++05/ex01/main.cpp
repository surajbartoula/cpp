/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:24 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/11 16:24:03 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat fr = Bureaucrat("francias", 150);
		std::cout << fr;
		Bureaucrat pr = Bureaucrat("grade form", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//Destructor is only called for fully constructed objects.
	try {
		Bureaucrat b = Bureaucrat("francias", 90);
		Form form = Form("grade form", 25, 12);
		form.beSigned(b);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b = Bureaucrat("francias", 25);
		Form form = Form("grade form", 25, 12);
		form.beSigned(b);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b = Bureaucrat("francias", 25);
		Form form = Form("grade form", 25, 12);
		b.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b = Bureaucrat("francias", 26);
		Form form = Form("grade form", 25, 12);
		b.signForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
