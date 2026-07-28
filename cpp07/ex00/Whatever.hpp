/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:14:58 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:14:59 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T& first, T& second)
{
	// std::swap(first, second);
	T	tmp;

	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T&	min( T& a, T& b )
{
	return ( a < b ? a : b );
}

template <typename T>
T&	max( T& a, T& b )
{
	return ( a > b ? a : b );
}

#endif
