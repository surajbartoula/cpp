/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:58:18 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/24 22:42:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &old);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator=(const Fixed &old);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	int toInt(void) const;
	float toFloat(void) const;

private:
	int _rawBits;
	static const int _fracBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif