/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:18:03 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:18:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Container>
void	PmergeMe::_print(const std::string& pref, Container& c)
{
	typedef typename Container::const_iterator const_iterator;

	std::cout << pref;
	for (const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::_insert(Container& nums, Container b)
{
	int n = 0;
	int power = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < b.size();)
	{
		++power;

		n = pow(2, power) - n;

		start += n;

		end = start - n;

		if (start > b.size())
			start = b.size();

		for (size_t j = start - 1; j >= end;)
		{
			nums.insert(std::upper_bound(nums.begin(), nums.end(), b[j]), b[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}


template <typename Container>
void PmergeMe::_insertionSort(Container& nums)
{
	for (size_t i = 1; i < nums.size(); ++i)
	{
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1])
		{
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}
}

template <typename Container>
void	PmergeMe::_mergeSort(Container& nums)
{
	Container	a;
	Container	b;
	size_t size = nums.size() / 2 + (nums.size() % 2);

	int unpaired = ((nums.size() % 2 == 0) ? -1 : nums[nums.size() - 1]);

	if (nums.size() == 2 || nums.size() == 3)
	{
		_insertionSort(nums);
		return ;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (i != size - 1 || nums.size() % 2 == 0)
		{
			int n = nums[i * 2], m = nums[i * 2 + 1];
			if (n > m)
				std::swap(n, m);
			a.push_back(m);
			b.push_back(n);
		}
	}
	if (unpaired != -1)
		b.push_back(unpaired);
	_mergeSort(a);
	_insert(a, b);
	nums = a;
}


/*
template <typename Container>
void	PmergeMe::_MergeInsertSort(Container& c, Container& left, Container& right)
{
	typedef typename Container::iterator iterator;

	iterator	l_it = left.begin();
	iterator	r_it = right.begin();

	// merge 
	while (l_it != left.end() && r_it != right.end())
	{
		if (*l_it < *r_it)
		{
			c.push_back(*l_it);
			++l_it;
		}
		else
		{
			c.push_back(*r_it);
			++r_it;
		}
	}

	// insert 
	// for (; l_it != left.end(); ++l_it)
	// 	c.push_back(*l_it);
	// for (; r_it != right.end(); ++r_it)
	// 	c.push_back(*r_it);

	// inserting remaining elements using binary insertion
	for (; l_it != left.end(); ++l_it)
	{
		iterator insert_pos = std::lower_bound(c.begin(), c.end(), *l_it);
		c.insert(insert_pos, *l_it);
	}
	for (; r_it != right.end(); ++r_it)
	{
		iterator insert_pos = std::lower_bound(c.begin(), c.end(), *r_it);
		c.insert(insert_pos, *r_it);
	}

}

template <typename Container>
void	PmergeMe::_divideSort(Container& c)
{
	typedef typename Container::iterator iterator;

	if (c.size() <= 1)
		return ;
	
	iterator mid = c.begin();
	
	std::advance(mid, c.size() / 2);
	Container	left(c.begin(), mid);
	Container	right(mid, c.end());

	_divideSort(left);
	_divideSort(right);

	c.clear();
	_MergeInsertSort(c, left, right);
	
}
*/

template <typename Container>
void	PmergeMe::_start(Container& c, double& time)
{
	clock_t	start = clock();
	// _divideSort(c);
	_mergeSort(c);
	clock_t	end = clock();

	time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; 
}

template <typename Container>
bool	PmergeMe::_isSorted(const Container& c)
{
	typedef typename Container::const_iterator const_iterator;

	for (const_iterator it = c.begin() + 1; it != c.end(); ++it)
		if (*(it - 1) > *it)
			return false;
	return true;
}

#endif