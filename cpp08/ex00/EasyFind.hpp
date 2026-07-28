/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:16 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:17 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int key)
{
	typename T::iterator it = std::find(container.begin(), container.end(), key);
	if (it != container.end())
		return it;
	throw std::out_of_range("404 Not Found");
}

#endif