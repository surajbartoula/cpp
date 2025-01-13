/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:42:10 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 11:04:27 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &old)
{
	(void)old;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
	(void)rhs;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string& formName, const std::string& target) {
	for (size_t i = 0; i < 3; i++) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formFuncs[i])(target));
			//Dereference a member function pointer and associate it with the current object (this).
			//formFuncs[i] is a member function pointer, so it needs to be combined with an instance of the class
			//(here, this) to invoke it.
			//The function takes a std::string parameter, so target is passed as the argument.
		}
	}
	std::cout << "Form does not exist." << std::endl;
	return (0);
}
AForm *Intern::makePresidentialForm(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyForm(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyForm(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

std::string Intern::forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::formCreationFunc Intern::formFuncs[] = {
	&Intern::makePresidentialForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyForm
};

//return ((this->*formFuncs[0])(target)); is equivalent to calling:
//return this->makePresidentialForm(target).

