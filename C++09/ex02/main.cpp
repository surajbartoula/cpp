/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:21:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/04 17:41:43 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe + numbers to sort" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		char *end;
		long nbr = strtol(argv[i], &end, 10);
		if (nbr > INT_MAX || nbr < 0 || errno == ERANGE || *end != '\0' || end == argv[i])
		{
			std::cout << "Error: Please provide positive integer sequence as argument." << std::endl;
			return 1;
		}
	}
	PmergeMe pm;
	pm.fill(argc, argv);
	pm.sort();

	return 0;
}

//The difference in processing time between std::vector and std::list comes down to how each data structure
//handles memory and iteration.

//Memory Layout & Cache Efficiency
//std::vector stores elements contiguously in memory
//std::list, on the other hand, is a doubly linked list where elements are scattered across memory. 
//Each element contains a pointer to the next andprevious elements,causing more cache misses and pointer dereferencing, making it slower.

//Iteration Performance
//Iterating over a std::vector is simple: it moves from one contiguous memory location to the next.
//Iterating over a std::list requires following pointers, which means the CPU must load new memory locations frequently, leading to more cache
//misses and branch mispredictions.


//std::vector manages a contiguous memory block, and for small vectors, there might be some overhead associated with allocating and managing
//this memory, especially if it involves resizing or reallocating (even if it's a small reallocation).
//std::list, on the other hand, uses dynamic allocation for each element, which, while generally less efficient, might have a lower
//overhead when dealing with small numbers of elements.