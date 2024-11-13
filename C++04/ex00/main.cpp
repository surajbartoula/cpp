/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/13 10:17:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();
	cat->makeSound();
	dog->makeSound();

	const Animal *ashley = new Cat();
	ashley->makeSound();

	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();
	std::cout << "Calling makeSound() on WrongAnimal:" << std::endl;
	wronganimal->makeSound();
	std::cout << "Calling makeSound() on WrongCat as a WrongAnimal pointer:" << std::endl;
	wrongcat->makeSound();

	delete dog;
	delete cat;
	delete ashley;
	delete wronganimal;
	delete wrongcat;

	return (0);
}