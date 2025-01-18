/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:12:31 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/18 21:41:35 by sbartoul         ###   ########.fr       */
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
	Awesome tab2[5];
	iter(tab, 5, print<int>);
	iter(tab2, 5, print<Awesome>);

	return (0);
}
