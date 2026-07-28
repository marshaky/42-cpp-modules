/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:37 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:38 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	this->database = rhs.database;
	return (*this);
}

const char*	BitcoinExchange::FileReadException::what() const throw()
{
	return ("An error accured while reading the file");
}

int	BitcoinExchange::ft_stoi(const std::string& str)
{
	int	i;

	std::istringstream(str) >> i;
	return (i);
}

float	BitcoinExchange::ft_stof(const std::string& str)
{
	float	f;

	std::istringstream(str) >> f;
	return (f);
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	int		year = ft_stoi(date.substr(0, 4));
	int		month = ft_stoi(date.substr(5, 2));
	int		day = ft_stoi(date.substr(8, 2));
	int		maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool	leapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	if (leapYear)
		maxDays[1] = 29;
	if (year < 1000 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > maxDays[month - 1])
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidVal(const std::string& s_val)
{
	bool	dot = false;

	if (s_val.empty() || !s_val.c_str())
		return (false);
	for(size_t i = 1; i < s_val.size(); ++i)
	{
		if (s_val.at(i) == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(s_val.at(i)))
			return (false);
	}
	return (true);
}

float	BitcoinExchange::getExchangeRate(const std::string& date)
{
	iterator	it = database.lower_bound(date);

	if (date != it->first && it != database.begin())
		--it;
	if (it == database.end())
		--it;
	return (it->second);
}

void	BitcoinExchange::databaseInit(std::string filename)
{
	std::ifstream	dataFile(filename.c_str());
	std::string		line;

	if(dataFile.fail() || !dataFile.is_open())
		throw BitcoinExchange::FileReadException();
	
	while (std::getline(dataFile, line))
	{
		if (!line.compare("date,exchange_rate"))
			continue ;
		size_t		lim = line.find(',');
		std::string	date = line.substr(0, lim);
		std::string	val = line.substr(lim + 1);

		database.insert(std::pair<std::string, float>(date, ft_stof(val)));
	}
	dataFile.close();
}

void	BitcoinExchange::exchangePrint(std::string filename)
{
	std::ifstream	infile(filename.c_str());
	std::string		line;

	if (infile.fail() || !infile.is_open())
		throw BitcoinExchange::FileReadException();

	while (std::getline(infile, line))
	{
		if (!line.compare("date | value"))
			continue ;
		/* date format check */
		bool	is_valid = line.length() > 13 \
							&& line.at(4) == '-'\
							&& line.at(7) == '-'\
							&& line.at(10) == ' ';

		if (!is_valid)
		{
			std::cout << BRED << "Error: " << CRST << "bad input: " \
				<< BWHT << line << CRST << std::endl;
			continue ;
		}

		/* 'date | value' delimiter check */
		size_t	lim = line.find('|');

		if (lim == line.npos)
		{
			std::cout << BRED << "Error: " << CRST << "bad input: " \
					<< BWHT << line << CRST << std::endl;
			continue ;
		}

		/* retrieving date and value */
		std::string	date = line.substr(0, lim - 1);
		std::string	s_val = line.substr(lim + 1);
		float		val = ft_stof(s_val);

		if (!isValidDate(date))
		{
			std::cout << BRED << "Error: " << CRST << "invalid date: " \
						<< BWHT << line << CRST << std::endl;
			continue ;
		}
		if (val < 0)
		{
			std::cout << BRED << "Error: " << CRST << "negative value: " \
						<< BWHT << line << CRST << std::endl;
			continue ;
		}
		if (val > 1000)
		{
			std::cout << BRED << "Error: " << CRST << "value limit exceeded: " \
						<< BWHT << line << CRST << std::endl;
			continue ;
		}
		if (!isValidVal(s_val))
		{
			std::cout << BRED << "Error: " << CRST << "invalid value: " \
						<< BWHT << line << CRST << std::endl;
			continue ;
		}

		/* calculating the exchange rate */
		float	rate = getExchangeRate(date);
		std::cout << BGRN << date << "=> " << val << " = " << rate * val << CRST << std::endl;
	}
}

