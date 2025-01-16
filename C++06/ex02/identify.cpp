/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:56:38 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 20:54:51 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base *generate(void) {
	std::srand(std::time(0));
	const size_t choice = std::rand() % 3;
	switch (choice)
	{
	case 0:
		std::cout << "Generated A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Generated B" << std::endl;
		return (new B());
	case 2:
		std::cout << "Generated C" << std::endl;
		return (new C());
	default:
		return (0);
	}
}

void identify(Base *p) {
	//dynamic_cast is used to safely cast pointers or references within an inheritance hierarchy.
	//Dynamic cast:Type-safe cast that checks if the object pointed to by p can be safely converted to
	//a pointer of a derived class (e.g., A, B, or C).
	//If the cast is invalid, dynamic_cast returns nullptr.
	//performing a type-safe cast from a base class pointer (p) to a derived class pointer (A*).
	const A *aPtr = dynamic_cast<A *>(p);
	if (aPtr)
	{
		std::cout << "Pointer identified as A" << std::endl;
		return;
	}
	const B *bPtr = dynamic_cast<B *>(p);
	if (bPtr)
	{
		std::cout << "Pointer identified as B" << std::endl;
		return ;
	}
	const C *cPtr = dynamic_cast<C *>(p);
	if (cPtr)
	{
		std::cout << "Pointer identified as C" << std::endl;
		return ;
	}
}

void identify(Base &p) {
	try
	{
		//dynamic_cast<A &>(p) attempts to cast the reference p to a reference of type A.
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference identified as A" << std::endl;
	}
	catch(const std::exception& e)
	//If p does not refer to an object of type A, dynamic_cast throws a std::bad_cast exception 
	//because it's being used with references.
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference identified as B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference identified as C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
