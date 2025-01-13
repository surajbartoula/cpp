/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:24 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/13 17:39:32 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat bureaucrat("Francias", 137);
    Bureaucrat highRank("Paris", 1);
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bender");
    PresidentialPardonForm presForm("Zaphod");

    try {
        highRank.signForm(robotomyForm);
        highRank.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        highRank.signForm(presForm);
        highRank.executeForm(presForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat lowRank("Jane", 150);
    try {
        lowRank.signForm(presForm);
        lowRank.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
