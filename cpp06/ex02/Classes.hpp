/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:53 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:54 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>

class Base {
	public:
		virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif