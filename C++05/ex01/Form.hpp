/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:53:29 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/11 16:06:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const size_t _gradetosign; //constant grade required to sign it.
	const size_t _gradetoexecute; //constant grade required to execute it.
public:
	Form(void);
	Form(const std::string name, const size_t gradetosign, const size_t gradetoexecute);
	Form(const Form &old);
	Form &operator=(const Form &rhs);
	~Form(void);

	class GradeTooHighException: public std::exception {
		const char *what(void) const throw();
	};
	class GradeTooLowException: public std::exception {
		const char *what(void) const throw();
	};

	const std::string& getName(void) const;
	bool getSigned(void) const;
	size_t getSignedGrade(void) const;
	size_t getExecutionGrade(void) const;
	void beSigned(const Bureaucrat& bureaucrat);
};

#endif