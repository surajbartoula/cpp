/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:16:19 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 22:32:12 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <list>

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span " << sp.longestSpan() << std::endl;

	Span sp1 = Span(200000);
	srand(time(NULL));
	for (unsigned int i = 0; i < 200000; i++)
		sp1.addNumber(rand() % 400000000);
	std::cout << "Shortest span " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span " << sp1.longestSpan() << std::endl;

	Span sp2 = Span(10);
	sp2.addNumber(4);
	sp2.addNumber(4);
	sp2.addNumber(6);
	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.addNumber(3);
	sp2.addNumber(7);
	std::cout << "Shortest span " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span " << sp2.longestSpan() << std::endl;

	Span sp3 = Span(1);
	try
	{
		sp3.addNumber(2);
		sp3.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Span sp4 = Span(1);
	try
	{
		sp4.addNumber(1);
		std::cout << sp4.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::list<unsigned int> lst;
	lst.push_back(4);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(8);
	lst.push_back(8);
	lst.push_back(5);
	lst.push_back(9);
	lst.push_back(12);
	Span sp5 = Span(8);
	sp5.addNumber(lst.begin(), lst.end());
	std::cout << "Shortest span " << sp5.shortestSpan() << std::endl;
	std::cout << "Longest span " << sp5.longestSpan() << std::endl;

	return 0;
}
