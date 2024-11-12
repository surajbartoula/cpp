/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:24:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/12 18:51:55 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// ANSI escape codes for color
    const std::string reset = "\033[0m";         // Reset to default
    const std::string red_text = "\033[31m";     // Red text color
    const std::string green_bg = "\033[42m";     // Green background color
	std::cout << green_bg << red_text << "--- Testing Deep Copy ---" << reset << std::endl;
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	dog->makeSound();
	cat->makeSound();
	srand(time(0));
	std::cout << green_bg << red_text << "--- Printing dog ideas ---" << reset << std::endl;
	dog->printidea();
	std::cout << green_bg << red_text << "--------------------------" << reset << std::endl;
	Dog dog1 = *dog;
	Dog dog2 = dog1;
	delete dog;
	std::cout << green_bg << red_text << "--- Printing dog1 ideas ---" << reset << std::endl;
	dog1.printidea();
	std::cout << green_bg << red_text << "--- Printing dog2 ideas ---" << reset << std::endl;
	dog2.printidea();
	std::cout << green_bg << red_text << "--- Printing cat ideas ---" << reset << std::endl;
	cat->printidea();
	delete cat;

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
