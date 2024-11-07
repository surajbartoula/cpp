/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/05 23:38:18 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();
	cat->makeSound();
	dog->makeSound();

	const Animal *ashley = new Cat();
	ashley->makeSound();

	delete dog;
	delete cat;
	delete ashley;

	return (0);
}