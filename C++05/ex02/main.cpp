/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:24 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 11:27:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b = Bureaucrat("Francias", 137);
	Bureaucrat f = Bureaucrat("Paris", 1);
	ShrubberyCreationForm shrubForm("Straberry");
	RobotomyRequestForm robotomyForm("Jarvis");
	PresidentialPardonForm presForm("Trump");

	b.executeForm(shrubForm);
	b.signForm(shrubForm);
	b.executeForm(shrubForm);

	f.signForm(robotomyForm);
	f.executeForm(robotomyForm);

	b.signForm(presForm);
	b.executeForm(presForm);

	f.signForm(presForm);
	f.executeForm(presForm);
}
