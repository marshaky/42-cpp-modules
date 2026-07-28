/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:25 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:26 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : capacity(0) {}

Span::Span(size_t N) : capacity(N) {}

Span::Span(const Span& rhs)
	: vec(rhs.vec)
	, capacity(rhs.capacity)
{}

Span::~Span() {}

const Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		capacity = rhs.capacity;
		vec = rhs.vec;
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (vec.size() == capacity)
		throw std::out_of_range("Span is full");
	vec.push_back(num);
}

int	Span::shortestSpan() const
{
	if (vec.size() <= 1)
		throw std::out_of_range("Can't find a span");
	
	std::vector<int>	tmp(vec);
	std::sort(tmp.begin(), tmp.end());

	int	sp = tmp[1] - tmp[0];

	for(size_t i = 2; i < vec.size(); ++i)
	{
		int	curr = vec[i] - vec[i - 1];
		sp = curr < sp ? curr : sp;
	}
	return (sp);
}

int	Span::longestSpan() const
{
	if (vec.size() <= 1)
		throw std::out_of_range("Can't find a span");
	return (*std::max_element(vec.begin(), vec.end()) \
	- *std::min_element(vec.begin(), vec.end()));
}
