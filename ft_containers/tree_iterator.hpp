#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{


	template <typename T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		typedef				T					node;
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
			else if (tmp->parent)
			{
				pointer	bis = tmp->parent;
				while (tmp == bis->right)
				{
					tmp = bis;
					bis = bis->parent;
				}
				tmp = bis;
			}
			return tmp;
		}

		pointer	decrement()
		{
			pointer	tmp = this->_node;

			if (tmp->left)
			{
				tmp = tmp->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			else if (tmp->parent)
			{
				pointer bis = tmp->parent;
				while(tmp == bis->left)
				{
					tmp = bis;
					bis = bis->parent;
				}
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

		tree_iterator	operator++(int)
		{
			tree_iterator	tmp = *this;
			this->_node = incremente();
			return tmp;
		}

		tree_iterator&	operator--()
		{
			this->_node = decrement();
			return *this;
		}

		tree_iterator	operator--(int)
		{
			tree_iterator	tmp = *this;
			this->_node = decrement();
			return tmp;
		}

	};

	template <class Iterator1, class Iterator2>
	bool operator==(const tree_iterator<Iterator1>& lhs, const tree_iterator<Iterator2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const tree_iterator<Iterator1>& lhs, const tree_iterator<Iterator2>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
