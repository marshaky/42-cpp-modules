/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:18:01 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:18:02 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*
* Here we focus on comparison-based sorting algorithm known as MergeInsertion.
* It was discovered by Ford and Johnson in 1959.
* Before D. E. Knuth coined the term MergeInsertion in his study of the algorithm in his book
* “The Art of Computer Programming, Volume 3: Sorting and Searching”,
* it was known only as Ford-Johnson Algorithm, named after its creators.
* The one outstanding property of MergeInsertion is that the number of comparisons it requires is close to
* the information-theoretic lower bound of log(n!) = n * log n - 1.4427 * n (for sorting n elements).
* This sets it apart from many other sorting algorithms.
* MergeInsertion can be described in three steps: first pairs of elements are compared;
* in the second step, the larger elements are sorted recursively;
* as a last step, the elements belonging to the smaller half are inserted
* into the already sorted larger half using binary insertion.
*/

# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYEL	"\033[1;33m"
# define BBLU	"\033[1;34m"
# define BWHT	"\033[1;37m"
# define CRST	"\033[0m"

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <iomanip>
# include <vector>
# include <deque>
# include <string>
# include <cstring>
# include <ctime>
# include <cmath>

class PmergeMe {
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;
		double				vecTime;
		double				deqTime;

	public:
		PmergeMe();
		PmergeMe(int ac, char** av);
		~PmergeMe();

	private:
		PmergeMe(const PmergeMe& rhs);
		PmergeMe&	operator=(const PmergeMe& rhs);
	
	public:
		void	operator()(int ac, char** av);

	public:
		class InvalidNumberException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class NotEnoughArgsException : public std::exception {
			public:
				const char*	what() const throw();
		};

	private:
		bool	isValidInput(int ac, char** av);

		template <typename Container>
		void	_print(const std::string& pref, Container& c);

		template <typename Container>
		void	_start(Container& c, double& time);

		template <typename Container>
		void	_mergeSort(Container& nums);

		template <typename Container>
		void	_insertionSort(Container& nums);

		template <typename Container>
		void	_insert(Container& nums, Container b);

		// template <typename Container>
		// void	_divideSort(Container& c);

		// template <typename Container>
		// void	_MergeInsertSort(Container& c, Container& left, Container& right);

		template <typename Container>
		bool	_isSorted(const Container& c);

};

# include "PmergeMe.tpp"

#endif