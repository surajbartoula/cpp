/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:53:26 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 11:40:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _signed(false), _gradetosign(10), _gradetoexecute(10) {
	std::cout << "Default form constructor called" << std::endl;
	if (_gradetosign < 1)
		throw GradeTooHighException();
	else if (_gradetosign > 150)
		throw GradeTooLowException();
	if (_gradetoexecute < 1)
		throw GradeTooHighException();
	else if (_gradetoexecute > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string name, const size_t gradetosign, const size_t gradetoexecute)
: _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexecute(gradetoexecute) {
	std::cout << "Form constructor called" << std::endl;
	if (_gradetosign < 1)
		throw GradeTooHighException();
	else if (_gradetosign > 150)
		throw GradeTooLowException();
	if (_gradetoexecute < 1)
		throw GradeTooHighException();
	else if (_gradetoexecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &old)
: _name(old._name), _signed(old._signed), _gradetosign(old._gradetosign), _gradetoexecute(old._gradetoexecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs) {
	std::cout << "Form copy assignment constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradetosign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const std::string &Form::getName() const {
	return (_name);
}

bool Form::getSigned() const {
	return (_signed);
}

size_t Form::getSignedGrade() const {
	return (_gradetosign);
}

size_t Form::getExecutionGrade() const {
	return (_gradetoexecute);
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form name: " << form.getName() << std::endl
		<< "Is form signed?: " << form.getSigned() << std::endl
		<< "Form execution grade: " << form.getExecutionGrade() << std::endl
		<< "Form signing grade: " << form.getSignedGrade() << std::endl;
	return (os);
}
