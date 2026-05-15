/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:59:28 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 01:59:45 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
# define __POINT_H__

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		Point(const float &x_val, const float &y_val);
		Point(const Point &copy);
		~Point() {}

		Point 	&operator=(const Point &copy);

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif