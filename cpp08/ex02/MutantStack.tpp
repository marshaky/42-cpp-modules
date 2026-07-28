/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:34 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:35 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>::stack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs)
	: std::stack<T>::stack(rhs)
{}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
const MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

#endif