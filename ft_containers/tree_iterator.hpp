#ifndef TREE_ITRETOR_HPP
# define TREE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	struct tree_iterator
	{
		typedef	typename	T::value_type		node;
		typedef				node*				pointer;
		typedef				node&				reference;

		pointer	_node;
		
	};
}

#endif
