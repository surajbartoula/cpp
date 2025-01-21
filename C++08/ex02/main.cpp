/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:15:11 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 23:36:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main() {
	MutantStack<int> mstack;
	mstack.push(6);
	mstack.push(8);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
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
	std::cout << mList.back() << std::endl;
	mList.pop_back();
	std::cout << mList.size() << std::endl;
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
	while (it2 != ite2)
	{
		std::cout << *it << std::endl;
		++it2;
	}
	return 0;
}
