/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:32:29 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 11:56:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = ideaList[rand() % 8];
}

Brain::Brain(const Brain &old) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = old.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::printidea(void) const {
	for (size_t i = 0; i < 8; i++) {
		std::cout << ideas[i] << std::endl;
	}
}

const std::string Brain::ideaList[] = {
	"Time to eat",
	"Time to sleep",
	"Time to play",
	"Time to cuddle",
	"Time to hunt",
	"Time to Zoomies",
	"Time to sniff",
	"Time to stare"
};
