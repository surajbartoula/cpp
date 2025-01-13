/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:30 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 15:08:32 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	size_t _grade;
public:
	class GradeTooHighException: public std::exception
	{
		//throw() is an exception specification, which specifies that the function does not throw any exceptions.
		//In modern C++ (C++11 and later), throw() has been deprecated and replaced with noexcept.
		//However, in older C++ standards (C++98 or C++03), throw() was used for the same purpose.
		//what() is a virtual function derived from base class std::exception when called it provides a description of the exception.
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char *what() const throw();
	};
	Bureaucrat(void);
	Bureaucrat(const std::string name, const size_t grade);
	Bureaucrat(const Bureaucrat &old);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	size_t getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm& form); //AForm is only referenced so full definition not required

	void executeForm(const AForm& form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif

//The << operator for std::ostream cannot be a member function of Bureaucrat because the left-hand
//operand (os) is of type std::ostream, not Bureaucrat.