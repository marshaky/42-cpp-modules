/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:15:56 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:15:57 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T*		array;
		size_t	_size;
	public:
		Array();
		Array(size_t size);
		Array(const Array& rhs);
		~Array();

		const Array&	operator=(const Array& rhs);
		T&				operator[](size_t idx);

		size_t	size() const;
};

#include "Array.tpp"


#endif