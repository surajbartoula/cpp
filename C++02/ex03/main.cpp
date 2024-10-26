/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:30:49 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:48 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 3)))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(-1, 3)))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	
	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 12)))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 8)))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
}
