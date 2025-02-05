/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:05:19 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/05 19:15:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const std::string& input) : _input(input) {}
RPN::RPN(const RPN& old): _stack(old._stack), _input(old._input) {}

RPN &RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
		_input = rhs._input;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
	return token == "-" || token == "+" || token == "*" || token == "/";
}

long long RPN::performOperation(long long a, long long b, const std::string& op) const {
    if (op == "+") {
        if ((b > 0 && a > std::numeric_limits<long long>::max() - b) ||
            (b < 0 && a < std::numeric_limits<long long>::min() - b)) {
            throw std::overflow_error("The total value exceeds long max value.");
        }
        return a + b;
    }
    
    if (op == "-") {
        if ((b > 0 && a < std::numeric_limits<long long>::min() + b) ||
            (b < 0 && a > std::numeric_limits<long long>::max() + b)) {
            throw std::overflow_error("The total value exceeds long max value.");
        }
        return a - b;
    }
    
    if (op == "*") {
        if (a != 0 && b != 0) {
            if ((a > 0 && b > 0 && a > std::numeric_limits<long long>::max() / b) ||
                (a < 0 && b < 0 && a < std::numeric_limits<long long>::max() / b) ||
                (a > 0 && b < 0 && b < std::numeric_limits<long long>::min() / a) ||
                (a < 0 && b > 0 && a < std::numeric_limits<long long>::min() / b)) {
				throw std::overflow_error("The total value exceeds long max value.");
            }
        }
        return a * b;
    }

    if (op == "/") {
        if (b == 0) throw std::runtime_error("Division by zero.");
        if (a == std::numeric_limits<long long>::min() && b == -1) {
            throw std::overflow_error("The total value exceeds long max value.");
        }
        return a / b;
    }

    throw std::runtime_error("Invalid operator.");
}

long long RPN::evaluate() {
	std::istringstream iss(_input);
	std::string token;
	while (iss >> token) {
		if (isdigit(token[0]) && token.size() < 2) {
			_stack.push(atoi(token.c_str()));
		} else if (isOperator(token)) {
			if (_stack.size() < 2) throw std::runtime_error("Invalid expression");
			long long b = _stack.top(); _stack.pop();
			long long a = _stack.top(); _stack.pop();
			_stack.push(performOperation(a, b, token));
		} else {
			throw std::runtime_error("Invalid token");
		}
	}
	if (_stack.size() > 1) throw std::runtime_error("invalid expression");
	return (_stack.top());
}
//The std::istringstream class allows you to treat a string as if it were an input stream (similar to std::cin).
//You can use the stream extraction operator (>>) to read tokens one by one, which is straightforward and efficient.