/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 02:00:24 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 02:00:41 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(const float &x_val, const float &y_val): x(x_val), y(y_val) {}

Point::Point(const Point &copy): x(copy.x), y(copy.y) {}

Point &Point::operator=(const Point &copy)
{
    if (this != &copy)
    {
        /* x and y are const */
    }
    return (*this);
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}