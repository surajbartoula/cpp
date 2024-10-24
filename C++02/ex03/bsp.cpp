/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:44:19 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/24 11:48:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool isInFront(Point p1, Point p2, Point p3) {
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())) > 0;
}

static bool isPointOnLine(const Point& point, const Point& a, const Point& b) {
	return ((point.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (point.getY() - b.getY()) == 0);
}

//Barycentric Subdivision Problems
bool bsp(const Point a, const Point b, const Point c, const Point point) {
	if (point == a || point == b || point == c)
		return (false); //If the point matches the vertices of triangle that means it's not inside the triangle.
	if (isPointOnLine(point, a, b) || isPointOnLine(point, b, c) || isPointOnLine(point, a, c))
		return (false);
	bool inFrontAB = isInFront(point, a, b);
	bool inFrontBC = isInFront(point, b, c);
	bool inFrontCA = isInFront(point, c, a);

	bool behind = !inFrontAB || !inFrontBC || !inFrontCA;
	bool inFront = inFrontAB || inFrontBC || inFrontCA;

	return !(behind && inFront);
}
