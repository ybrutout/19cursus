#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{


	template <typename T>
	class tree_iterator
	{
		public:
		typedef	typename	T::node				node;
		typedef				node*				pointer;
		typedef				node&				reference;

		pointer	_node;

		private:

		pointer	incremente()
		{
			pointer	tmp = this->_node;
			if (tmp->right)
			{
				tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			else
			{
				pointer	bis = tmp->parent;
				while (tmp == bis->right)
				{
					tmp = bis;
					bis = bis->parent;
				}
				if (tmp->right != bis)
					tmp = bis;
			}
			return tmp;
		}

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor for an empty tree_iterator*/
		tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		tree_iterator(pointer x) : _node(x)
		{}

		/*Copy constructor*/
		tree_iterator(tree_iterator const& cpy) : _node(cpy._node)
		{}

		/*Destructor*/
		~tree_iterator()
		{}

		tree_iterator		&operator=(tree_iterator rhs)
		{
			this->_node = rhs._node;
			return *this;
		}

		operator tree_iterator<const T>() const { return this->_node; }
		/*-----------------------------------------------------------------------------------------------------------*/

		pointer	const& base() const
		{
			return this->_node;
		}

		reference	operator*() const
		{ return *this->_node; }

		tree_iterator&	operator++()
		{
			this->_node = incremente();
			return *this;
		}

		/*
		random_access_iterator&	operator++()
		{
			++this->_p;
			return *this;
		}

		random_access_iterator	operator++(int)
		{
			return this->_p++;
		}

		random_access_iterator& operator--()
		{
			--this->_p;
			return *this;
		}

		random_access_iterator  operator--(int)
		{
			return this->_p--;
		}
		*/

	};
}

#endif
