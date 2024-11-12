/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:32:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/12 18:47:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Brain {
private:
	std::string ideas[100];
	static const std::string ideaList[];
public:
	Brain(void);
	Brain(const Brain &old);
	Brain &operator=(const Brain &rhs);
	~Brain(void);
	void printidea(void) const;
};

#endif