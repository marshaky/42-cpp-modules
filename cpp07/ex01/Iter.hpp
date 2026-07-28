/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:16:40 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:16:41 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	blabla(const T& val)
{
	std::cout << "blabla [ " << val << " ]" << std::endl;
}

template <typename T>
void	iter(T* arr, size_t size, void(*func)(T&))
{
	for (size_t i = 0; i < size; ++i)
		func(arr[i]);
}

template <typename T>
void	iter(T* arr, size_t size, void(*func)(T const &))
{
	for (size_t i = 0; i < size; ++i)
		func(arr[i]);
}

#endif