/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:30 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/10 22:28:32 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string _name;
	size_t _grade;
public:
	class GradeTooHighException: public std::exception
	{
		//throw() is an exception specification, which specifies that the function
		//does not throw any exceptions.
		//In modern C++ (C++11 and later), throw() has been deprecated and replaced with noexcept.
		//However, in older C++ standards (C++98 or C++03), throw() was used for the same purpose.
		//what() is a virtual function derived from base class std::exception when called
		//it provides a description of the exception.
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
	//keeping last const on .hpp means when implementing getName on .cpp you will not
	//modify the state of a class object ie the variable from class cannot be touched.
	size_t getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif

//The << operator for std::ostream cannot be a member function of Bureaucrat because the left-hand
//operand (os) is of type std::ostream, not Bureaucrat.