/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:04:53 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 19:16:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	int arr[] = {10, 12, 14, 16, 18, 20, 22};
	std::vector<int> numVec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try {
		std::vector<int>::iterator it = easyfind(numVec, 18);
		std::cout << *it << " was found on the vector container." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}
