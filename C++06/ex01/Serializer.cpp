/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:49:53 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 22:49:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	std::cout << "Default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer& old) {
	std::cout << "Copy constructor called." << std::endl;
	(void)old;
}

Serializer& Serializer::operator=(const Serializer& rhs) {
	std::cout << "Copy assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}

Serializer::~Serializer(void) {
	std::cout << "Destructor called.";
}

//uintptr_t used to store pointer values as integers
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

//Convert uintptr_t back into a pointer of type Data*
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

//reinterpret_cast
//cast operator used to convert one type to another, often between completely
//unrelated types, such as converting a pointer to an integer. It's considered
//a low-level cast and can be unsafe in some situations. It performs a bitwise
//conversion,meaning it doesn't change the underlying data,only how it's interpreted