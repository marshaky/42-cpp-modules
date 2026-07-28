/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:15:54 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:15:55 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array()
	: array(NULL)
	, _size(0)
{}

template <typename T>
Array<T>::Array(size_t size)
{
	array = new T[size];

	for (size_t i = 0; i < size; ++i)
		array[i] = T();
	_size = size;
}

template <typename T>
Array<T>::Array(const Array& rhs)
{
	array = new T[rhs._size];

	for (size_t i = 0; i < rhs._size; ++i)
		array[i] = rhs.array[i];
	_size = rhs._size;
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
	array = NULL;
	_size = 0;
}

template <typename T>
const Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (array)
		delete[] array;
	if (this != &rhs)
	{
		array = new T[rhs._size];

		for (size_t i = 0; i < rhs._size; ++i)
			array[i] = rhs.array[i];
		_size = rhs._size;
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](size_t idx)
{
	if (idx >= _size)
		throw std::out_of_range("Invalid index");
	return (array[idx]);
}

template <typename T>
size_t	Array<T>::size() const
{
	return (_size);
}


#endif