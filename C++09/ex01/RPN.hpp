/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:05:36 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/05 14:28:07 by sbartoul         ###   ########.fr       */
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
#include <climits>

class RPN {
private:
	std::stack<long long> _stack;
	std::string _input;
	bool isOperator(const std::string& token) const;
	long long performOperation(long long a, long long b, const std::string& op) const;
public:
	RPN();
	RPN(const std::string& input);
	RPN(const RPN& old);
	RPN& operator=(const RPN& rhs);
	~RPN();
	long long evaluate();
};

#endif

//operators follow their operands