/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:33:26 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 23:03:40 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data *original = new Data();
	original->name = "Test";
	original->value = 42;

	uintptr_t serialized = Serializer::serialize(original); //Serialized to uintptr_t

	// Deserialize the uintptr_t back to a Data pointer
	Data* deserialized = Serializer::deserialize(serialized);

	if (original == deserialized)
		std::cout << "Pointers are equivalent" << std::endl;
	std::cout << "Original data ptr: " << original << std::endl;
	std::cout << "The name is " << deserialized->name << std::endl;
	std::cout << "The value is " << deserialized->value << std::endl;
	std::cout << "Serialized data ptr: 0x" << std::hex << serialized << std::endl;
	std::cout << "Deserialized data ptr: " << deserialized << std::endl;
}
