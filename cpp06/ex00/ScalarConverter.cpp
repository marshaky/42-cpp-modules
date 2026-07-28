/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:05 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:06 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& str)
{
	if (!str[0])
		throw ScalarConverter::InvalidInputException("ScalarConverter Exception: Empty input");
	std::string	trimmed = strtrim(str, " \t\n");
	if (strchr(trimmed.c_str(), ' ') || strchr(trimmed.c_str(), '\t')\
	|| strchr(trimmed.c_str(), '\n') || signChecker(trimmed))
		throw ScalarConverter::InvalidInputException("ScalarConverter Exception: Invalid characters detected");
	if (trimmed.end() - 1 != trimmed.begin())
		trimmed = strtrim(trimmed, "0");
	parser(trimmed);
	display(trimmed);
}

std::string strtrim(const std::string& str, const std::string& chars)
{
	if (allZero(str))
	{
		std::string s;
		s.insert(0, 1,'0');
		return s;
	}

	size_t	first = str.find_first_not_of(chars);
	size_t	last = str.find_last_not_of(chars);
    
	if (first == std::string::npos || last == std::string::npos)
		return "";

	return str.substr(first, last - first + 1);
}

bool	allZero(const std::string& str)
{
	for(const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it != '0')
			return false;
	}
	return true;
}

bool	safeStoi(const std::string& str, int& _n)
{
	int	sign = 1;
	int	i = 0;
	int	n;

	if (str == "-2147483648")
	{
		_n = INT_MIN;
		return false;
	}
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	for (; str[i] && str[i] > 47 && str[i] < 58; ++i)
	{
		n = _n;
		_n = (_n * 10) + (str[i] - '0');
		if (n > _n)
			return (true);
	}
	_n = _n * sign;
	return false;
}

bool	signChecker(const std::string& trimmed)
{
	std::size_t	plus = trimmed.find('+');
	std::size_t	minus = trimmed.find('-');

	return ((plus != std::string().npos && plus) || \
	(minus != std::string().npos && minus) ? true : false);
}

void	parser(std::string& str)
{
	int	dot = 0;

	for (iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it  == '.')
		{
			if (it + 1 == str.end() || *(it + 1) == 'f')
				throw ScalarConverter::InvalidInputException("ScalarConverter Exception: Invalid input");
			if (it == str.begin() || !std::isdigit(*(it - 1)))
				str.insert(*(it++), "0");
			dot++;
		}
		if ((*it != '+' && *it != '-' && *it != '.' \
			&& !strchr("infa", *it) && !std::isdigit(*it)) \
			|| ((*it == '+' || *it == '-') && it != str.begin()) || dot > 1)
		{
			std::cerr << "Error: symbol: " << *it << std::endl;
			throw ScalarConverter::InvalidInputException("ScalarConverter Exception: Undefined Symbol");
		}
	}
	strChecker(str);
}

void	strChecker(const std::string& str)
{
	int			i;
	int			digit = 0;
	std::string	input[8] = {"inf", "-inf", \
 	"+inf", "inff", "-inff", "+inff", "nan", "nanf"};

	for (const_iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it))
			digit++;
	for (i = 0; digit == 0 && i < 8; ++i)
                if (str == input[i])
                        break ;
	if (i == 8)
		throw ScalarConverter::InvalidInputException("Invalid option");

	if (digit > 0)
	{
		for (size_t i = 0; i < str.size(); ++i)
			if (strchr("ina", str[i]) || (str[i] == 'f' && i != str.length() - 1))
				throw ScalarConverter::InvalidInputException("ScalarConverter Exception: Invalid option");
	}
}

void display(const std::string& str)
{
	if (str.find('n') != std::string::npos)
	{
		std::cout << "Char: Impossible\n"
				 << "Int: Impossible\n";

		std::cout << "Float: " << str;
		if (str != "nanf" && (str.find('f') == std::string::npos || str.find('f') == str.length() - 1))
			std::cout << 'f';
		std::cout << '\n';

		std::cout << "Double: ";
		if (str != "inf" && str != "+inf" && \
		str != "-inf" && *(str.end() - 1) == 'f')
			std::cout << str.substr(0, str.length() - 1);
		else
			std::cout << str;
		std::cout << '\n';
	}
    else
    {
		displayNum(str);
    }
}

void	displayNum(const std::string& str)
{
	int	intNum = 0;
	float	floatNum = atof(str.c_str());

	std::ostringstream ss;
	ss << floatNum;
	std::string sfloat = ss.str();

	int	overflow = safeStoi(str, intNum);

	/* char */
	std::cout << "Char: ";
	if ((intNum >= -128 && intNum < 32) || intNum == 127)
		std::cout << "Non-displayable";
	else if (intNum < -128 || intNum > 127)
		std::cout << "Overflow";
	else
		std::cout << static_cast<char>(intNum);
	std::cout << std::endl;

	/* int */
	std::cout << "Int: ";
	if (overflow)
		std::cout << "Overflow";
	else
		std::cout << intNum;
	std::cout << std::endl;

	/* float */
	try {
		std::cout << "Float: " << floatNum;
		if (floatNum == 0 || floatNum == std::numeric_limits<float>::infinity() ||
			floatNum == -std::numeric_limits<float>::infinity() ||
			std::isnan(floatNum))
		{
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	} catch (const std::out_of_range&) {
		std::cout << "Float: Overflow" << std::endl;
	} catch (...) {
		std::cout << "Float: Invalid conversion" << std::endl;
	}

    /* double */
	double doubleNum;
    try {
		doubleNum = static_cast<double>(floatNum);
		std::cout << "Double: " << doubleNum;
		if (doubleNum == 0 || doubleNum == std::numeric_limits<double>::infinity() ||
			doubleNum == -std::numeric_limits<double>::infinity() ||
            std::isnan(doubleNum)) {
            std::cout << ".0";
        }
        std::cout << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "Double: Overflow" << std::endl;
    } catch (...) {
        std::cout << "Double: Invalid conversion" << std::endl;
    }
}


bool	checkAfterDot(const std::string& str)
{
	int 		i = 1;
	int			zero = 0;
	std::string	check = strchr(str.c_str(), '.');

	if (check.c_str() == NULL)
		return false;
	for (; check[i] && check[i] == '0'; ++i)
		zero++;
	return (!isdigit(check[i]) || zero > 2);
}