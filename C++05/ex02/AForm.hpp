/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:24:58 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 10:45:04 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const size_t _gradetosign; //constant grade required to sign it.
	const size_t _gradetoexecute; //constant grade required to execute it.
public:
	AForm(void);
	AForm(const std::string name, const size_t gradetosign, const size_t gradetoexecute);
	AForm(const AForm &old);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm(void);

	class GradeTooHighException: public std::exception {
		const char *what(void) const throw();
	};
	class GradeTooLowException: public std::exception {
		const char *what(void) const throw();
	};
	class FormNotSignedException: public std::exception {
		const char *what(void) const throw();
	};

	const std::string& getName(void) const;
	bool getSigned(void) const;
	size_t getSignedGrade(void) const;
	size_t getExecutionGrade(void) const;
	void beSigned(const Bureaucrat& bureaucrat);
	void setSigned(bool val);
	virtual void execute(const Bureaucrat& executor) const = 0;
};

#endif