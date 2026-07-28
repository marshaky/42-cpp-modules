/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:28 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:29 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <climits>
# include <cstdlib>
# include <vector>

class Span {
	private:
		std::vector<int>	vec;
		size_t				capacity;
	private:
		Span();
	public:
		Span(size_t N);
		Span(const Span& rhs);
		~Span();

		const Span&	operator=(const Span& rhs);

		void	addNumber(int num);

		template <typename iter>
		void	addNumber(iter begin, iter end);

		int		shortestSpan() const;
		int		longestSpan() const;
};

template <typename iter>
void	Span::addNumber(iter begin, iter end)
{
	for (; begin < end; ++begin)
		addNumber(*begin);
}

#endif