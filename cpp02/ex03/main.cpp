/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:35 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 19:31:19 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	area(const Point &a, const Point &b, const Point &c)
{
    return std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
                     b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                     c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	Fixed	total_area = area(a, b, c);
	Fixed	area1 = area(point, b, c);
	Fixed	area2 = area(a, point, c);
	Fixed	area3 = area(a, b, point);
	
	return (total_area == area1 + area2 + area3);
}

int main()
{
	/* Test case 1 */
	Point	a1(0, 0);
	Point	b1(4.5f, 0);
	Point	c1(0, 3.5f);
	Point	point1(1.5f, 1.5f);

	std::cout << "Test case 1: Point is inside triangle: " << std::boolalpha << bsp(a1, b1, c1, point1) << std::endl;

	/* Test case 2 */
	Point	a2(0, 0);
	Point	b2(4, 0);
	Point	c2(2, 2);
	Point	point2(1, 1);

	std::cout << "Test case 2: Point is inside triangle: " << std::boolalpha << bsp(a2, b2, c2, point2) << std::endl;

	/* Test case 3 */
	Point	a3(0, 0);
	Point	b3(4, 0);
	Point	c3(0, 4);
	Point	point3(2, 2);

	std::cout << "Test case 3: Point is inside triangle: " << std::boolalpha << bsp(a3, b3, c3, point3) << std::endl;

	/* Test case 4: Point is outside the triangle */
	Point	a4(0, 0);
	Point	b4(4.5f, 0);
	Point	c4(0, 3.5f);
	Point	point4(5, 5);

	std::cout << "Test case 4: Point is inside triangle: " << std::boolalpha << bsp(a4, b4, c4, point4) << std::endl;

	/* Test case 5: Point is on the edge of the triangle */
	Point	a5(0, 0);
	Point	b5(4, 0);
	Point	c5(2, 2);
	Point	point5(2, 0);

	std::cout << "Test case 5: Point is inside triangle: " << std::boolalpha << bsp(a5, b5, c5, point5) << std::endl;

	return (0);
}