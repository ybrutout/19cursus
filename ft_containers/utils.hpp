#ifndef UTILS_HPP
# define UTILS_HPP
# include "iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{
		template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type __distance(InputIterator __first,
	InputIterator __last, input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type __n = 0;
		while(__first != __last)
		{
			++__first;
			++__n;
		}
		return __n;
	}

	template <class RandomAccessIterator>
	typename iterator_traits<RandomAccessIterator>::difference_type __distance
	(RandomAccessIterator __first, RandomAccessIterator __last, random_access_iterator_tag)
	{
		return __last - __first;
	}

	template <typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		return __distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
	}
}

#endif
