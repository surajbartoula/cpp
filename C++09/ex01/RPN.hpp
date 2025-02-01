/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:05:36 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/26 01:11:22 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class RPN {
private:
	std::stack<int> _stack;
	std::string _input;
	bool isOperator(const std::string& token) const;
	int performOperation(int a, int b, const std::string& op) const;
public:
	RPN();
	RPN(const std::string& input);
	RPN(const RPN& old);
	RPN& operator=(const RPN& rhs);
	~RPN();
	int evaluate();
};

#endif

//operators follow their operands