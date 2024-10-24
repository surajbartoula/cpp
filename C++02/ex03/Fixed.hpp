/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:44:37 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/23 17:46:43 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &old);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator=(const Fixed &old);
	~Fixed(void);

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed &operator++();
	Fixed operator++(int);

	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	int toInt(void) const;
	float toFloat(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _rawBits;
	bool _neg;
	static const int _fracBits;
	static unsigned int pow(unsigned int num, unsigned int pow);
	static float abs(float num);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
