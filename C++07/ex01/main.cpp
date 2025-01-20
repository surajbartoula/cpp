/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:12:31 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/20 10:26:25 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Awesome {
private:
	int _n;
public:
	Awesome(): _n(42) {return;}
	int get() const {return this->_n;}
};

std::ostream& operator<<(std::ostream& os, Awesome const& rhs) {os << rhs.get(); return os;}

template<typename T>
void print(T const& x) {std::cout << x << std::endl; return;}
//Since std::cout << is overloaded for Awesome, the get method of awesome is called
//to retrieve the value of _n

int main() {
	int tab[] = {0, 1, 2, 3, 4};
	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string stringArray[3] = {"Hello", "world", "!!!"};
	Awesome tab2[5];
	iter(tab, 5, print<int>);
	iter(charArray, 5, print<char>);
	iter(stringArray, 3, print<std::string>);
	iter(tab2, 5, print<Awesome>);

	return (0);
}
