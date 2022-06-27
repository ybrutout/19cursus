#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include "binary_tree.hpp"
# include "pair.hpp"

namespace ft
{
	template < class Key, class T,class Compare = ft::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
		typedef				Key									key_type;
		typedef				T									mapped_type;
		typedef				ft::pair<key_type, mapped_type>		value_type;
		typedef				Compare								key_compare;
		//key_compare class je sais pas quoi ... j'ai pas compris
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;

		private:
		typedef typename	ft::Binary_Tree<key_type, mapped_type, key_compare, allocator_type>		tree_type;

		public:
		typedef typename	tree_type::iterator					iterator;
		//const iterator
		//reverse
		//const reverse
		typedef				ptrdiff_t							difference_type;
		typedef				size_t								size_type;

		private:
		tree_type		_tree;

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor*/
		explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
		{}

		/*Range constructor*/
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _tree(comp, alloc)
		{
			while (first != last)
				this->_tree.insert(*first);
		}

		/*Copy constructor*/
		map (const map& x) : _tree(x._t)
		{}

		/*Deconstructor*/
		~map()
		{}

		map& operator= (const map& x)
		{}


		/*-----------------------------------------------------------------------------------------------------------*/
	};
};

#endif
