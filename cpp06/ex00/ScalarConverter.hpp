/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:12 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:42 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <cstring>
#include <string>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <limits>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

typedef std::string::iterator iterator;
typedef std::string::const_iterator const_iterator;

class ScalarConverter
{
public:
	static void	convert(const std::string& str);
public:
	class InvalidInputException : public std::exception
	{
		private:
			const char	*err;
		public:
			InvalidInputException(const char* err) : err(err) {}
			const char*	what() const throw() { return (err); }
	};
private:
    ScalarConverter();
};

std::string strtrim(const std::string& str, const std::string& chars);
bool		safeStoi(const std::string& str, int& _n);

bool		signChecker(const std::string& trimmed);
void		strChecker(const std::string& str);
bool		checkAfterDot(const std::string& str);
bool		allZero(const std::string& str);

void		parser(std::string& str);
void		display(const std::string& str);
void		displayNum(const std::string& str);

#endif