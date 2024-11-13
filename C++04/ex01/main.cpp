/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/13 20:02:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	const int numAnimals = 10;
	Animal *animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new Dog();
	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < numAnimals; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	srand(time(0));
	const Dog *lucky = new Dog();
	const Cat *ashley = new Cat();

	lucky->makeSound();
	ashley->makeSound();
	std::cout << "Lucky idea printed:" << std::endl;
	lucky->printidea();
	const Dog lucky1 = *lucky;
	delete lucky;
	Dog lucky2 = lucky1;
	std::cout << "Lucky1 idea printed:" << std::endl;
	lucky1.printidea();
	std::cout << "Lucky2 idea printed:" << std::endl;
	lucky2.printidea();
	std::cout << "ashley idea printed:" << std::endl;
	ashley->printidea();
	delete ashley;
	return (0);
}

//Memory management, deep copying, and polymorphism

//		Purpose of Deep Copy

// •	When an object has a pointer (like Brain* in Dog and Cat), a shallow copy only copies 
// 		the pointer address, meaning two objects might share the same memory for Brain.
// •	Deep copying means each copy of Dog or Cat has its own separate copy of the Brain, 
// 		so changes in one won’t affect the other.

//Main purpose of the exercise
//Memory management:Ensure each dynamically allocated Brain is properly freed to prevent memory leaks.
//Deep copy:Tests that dog and cat objects aren't sharing the same Brain memory, so each copy has its own independent Brain.
//Polymorphism: Allows us to handle Dog and Cat objects as Animal* pointers in a single array, calling the correct destructor and functions based on the actual object type(Dog or Cat).
//By making Brain a member of Dog and Cat, the exercise demonstrates composition, where an object
//(e.g., Dog or Cat) owns another object (e.g., Brain).
