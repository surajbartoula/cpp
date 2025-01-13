/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:42:29 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 10:03:36 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	typedef AForm *(Intern::*formCreationFunc)(const std::string &target);

	Intern(void);
	Intern(const Intern &old);
	Intern &operator=(const Intern &rhs);
	~Intern(void);
	//Dynamic Object Creation with Factory Design Pattern
	//Encapsulation and Abstraction
	//The Intern class encapsulates the logic of creating forms, abstracting away the
	//complexities of dynamic object creation from the rest of the system.
	AForm *makeForm(const std::string &formName, const std::string &target);
private:
	AForm *makePresidentialForm(const std::string &target);
	AForm *makeRobotomyForm(const std::string &target);
	AForm *makeShrubberyForm(const std::string &target);
	static std::string forms[3];
	static formCreationFunc formFuncs[3];
};

#endif

/**The Factory Method Design Pattern and its role in clean, extensible software design.
Principles of object-oriented programming (encapsulation, inheritance, polymorphism).
Writing robust code with proper error handling.
Importance of testing to validate program functionality.
Best practices for writing maintainable and scalable C++ code.**/

/**Abstracts the complexities of instantiating specific objects, adhering to the principles of
encapsulation and abstraction. **/