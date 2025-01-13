/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:24:51 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 22:47:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _signed(false), _gradetosign(10), _gradetoexecute(10) {
	std::cout << "Default AForm constructor called" << std::endl;
	if (_gradetosign < 1)
		throw GradeTooHighException();
	else if (_gradetosign > 150)
		throw GradeTooLowException();
	if (_gradetoexecute < 1)
		throw GradeTooHighException();
	else if (_gradetoexecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, const size_t gradetosign, const size_t gradetoexecute)
: _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexecute(gradetoexecute) {
	std::cout << "Named AForm constructor called" << std::endl;
		if (_gradetosign < 1)
		throw GradeTooHighException();
	else if (_gradetosign > 150)
		throw GradeTooLowException();
	if (_gradetoexecute < 1)
		throw GradeTooHighException();
	else if (_gradetoexecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &old)
: _name(old._name), _signed(old._signed), _gradetosign(old._gradetosign), _gradetoexecute(old._gradetoexecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs) {
	std::cout << "AForm copy assignment constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

AForm::~AForm(void) {
	std::cout << "AForm destructor called" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradetosign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const std::string &AForm::getName() const {
	return (_name);
}

bool AForm::getSigned() const {
	return (_signed);
}

size_t AForm::getSignedGrade() const {
	return (_gradetosign);
}

size_t AForm::getExecutionGrade() const {
	return (_gradetoexecute);
}

void AForm::setSigned(bool val) {
	_signed = val;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm name: " << form.getName() << std::endl
		<< "Is form signed?: " << form.getSigned() << std::endl
		<< "AForm execution grade: " << form.getExecutionGrade() << std::endl
		<< "AForm signing grade: " << form.getSignedGrade() << std::endl;
	return (os);
}
