/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:15:11 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/22 19:56:12 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	MutantStack<int> mstack;
	mstack.push(6);
	mstack.push(8);
	//The top() function in a stack is used to access the element at the top of the stack without removing it
	std::cout << "Working with adding single element" << std::endl;
	std::cout << "The top of the stack is element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After removing one element the total size of the stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(12);
	mstack.push(19);
	mstack.push(0);
	mstack.push(90);
	mstack.push(103);
	mstack.push(80);
	mstack.pop();
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Afer adding more element the stack has below element: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::list<int> mList;
	mList.push_back(6);
	mList.push_back(8);
	std::cout << "Working with adding ranges." << std::endl;
	std::cout << "The element on the back is: " << mList.back() << std::endl;
	mList.pop_back();
	std::cout << "After removing element the size is: " << mList.size() << std::endl;
	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(12);
	mList.push_back(19);
	mList.push_back(0);
	mList.push_back(90);
	mList.push_back(103);
	mList.push_back(80);
	mList.pop_back();
	std::list<int>::iterator it2 = mList.begin();
	std::list<int>::iterator ite2 = mList.end();
	++it2;
	--it2;
	std::cout << "After adding some elements the elements on the stack are: " << std::endl;
 	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << std::endl;
	std::cout << "Iterating with const_iterators" << std::endl;
	MutantStack<int> mstack1;
	mstack1.push(10);
	mstack1.push(20);
	mstack1.push(30);
	MutantStack<int>::const_iterator cit = mstack1.begin();
	MutantStack<int>::const_iterator cite = mstack1.end();
	while (cit != cite) {
		std::cout << *cit << std::endl;
		++cit;
	}
	return 0;
}
