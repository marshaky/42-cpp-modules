/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:39 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYEL	"\033[1;33m"
# define BBLU	"\033[1;34m"
# define BWHT	"\033[1;37m"
# define CRST	"\033[0m"

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <exception>
# include <map>

class BitcoinExchange {
	typedef std::map<std::string, float>::iterator iterator;
	private:
		std::map<std::string, float>	database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	
		void	databaseInit(std::string filename);
		void	exchangePrint(std::string filename);

	public:
		class FileReadException : public std::exception {
			public:
				const char*	what() const throw();
		};

	private:
		int		ft_stoi(const std::string& str);
		float	ft_stof(const std::string& str);
		void	retrieveDateVal(std::string line, size_t lim);
		bool	isValidDate(const std::string& date);
		bool	isValidVal(const std::string& s_val);
		float	getExchangeRate(const std::string& date);

};

#endif