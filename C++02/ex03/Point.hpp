/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/23 22:37:48 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &old);
	Point &operator=(const Point &old);
	~Point(void);
	bool operator==(const Point &rhs) const;

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
private:
	const Fixed x;
	const Fixed y;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif