/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:24 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 13:21:30 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf != NULL) {
		Bureaucrat b = Bureaucrat("Francias", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
	}
	delete rrf;

	Intern shruberryIntern;
	AForm *ssf;
	ssf = shruberryIntern.makeForm("presidential pardon", "Tender");
	if (ssf != NULL) {
		Bureaucrat bob = Bureaucrat("USA", 50);
		bob.signForm(*ssf);
		bob.executeForm(*ssf);
	}
	delete ssf;

	Intern presIntern;
	AForm *ppf;
	ppf = presIntern.makeForm("shrubbery creation", "Tinker");
	if (ppf != NULL) {
		Bureaucrat boby = Bureaucrat("UK", 140);
		boby.signForm(*ppf);
		boby.executeForm(*ppf);
	}
	delete ppf;
}
