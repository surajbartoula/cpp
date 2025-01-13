/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:38:31 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/12 11:29:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

#define TREE "    ccee88oo8888oo\n" \
             "  C8O8O8Q8PoOb o8oo\n" \
             " dOB69QO8PdUOpugoO9bD\n" \
             "CgggbU8OU qOp qOdoUOdcb\n" \
             "   6OuU  /p u gcoUodpP\n" \
             "      \\\\//  /douUP\n" \
             "        \\\\////\n" \
             "         |||/\\\\\n" \
             "         |||\\/\\\\\n" \
             "         |||||||\n" \
             "   .....//||||\\\\....\n"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& old);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm(void);

	void execute(const Bureaucrat& executor) const;
};

#endif
