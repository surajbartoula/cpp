/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:38:08 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 22:27:30 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
: AForm("Shruberry Creation Form", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shruberry Creation Form", 145, 137), _target(target) {
	std::cout << "ShurbberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old)
: AForm(old), _target(old._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << "ShrubberryCreationForm copy assignment constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	setSigned(rhs.getSigned());
	_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShruberryCreatorForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecutionGrade())
		throw GradeTooLowException();
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << (_target + "_shrubbery") << std::endl;
		return;
	}
	file << TREE << std::endl;
	file.close();
}
