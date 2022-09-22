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
		typedef				tree_iterator<T>	himself;

		pointer	_node;

		private:

		pointer	incremente()
		{
			pointer tmp = this->_node;
			pointer	bis = tmp->parent;

			if (tmp->is_leaf())
				return tmp;
			if (tmp->right && !tmp->right->is_leaf())
			{
				tmp = tmp->right;
				while (tmp->left && !tmp->left->is_leaf())
					tmp = tmp->left;
				return tmp;
			}
			while (bis && tmp == bis->right)
			{
				tmp = bis;
				bis = bis->parent;
			}
			if (bis && tmp == bis->left)
				return bis;
			return _node->end;
		}

		pointer	decrement()
		{
			pointer tmp = _node;
			pointer bis = tmp->parent;

			if (tmp->is_leaf())
				return tmp;
			if (tmp->left && !tmp->left->is_leaf())
			{
				tmp = tmp->left;
				while (tmp->right && !tmp->right->is_leaf())
					tmp = tmp->right;
				return tmp;
			}
			while(bis && tmp == bis->left)
			{
				tmp = bis;
				bis = bis->parent;
			}
			if (bis && tmp == bis->right)
				return bis;
			return _node->end;
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

		bool	operator==(const himself& x) const
		{
			return _node == x._node;
		}

		bool	operator!=(const himself& x) const
		{
			return _node != x._node;
		}

	};

	template <typename T>
	class const_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		typedef				T						node;
		typedef	const		node*					pointer;
		typedef	const		node&					reference;
		typedef				const_tree_iterator<T>	himself;
		typedef				tree_iterator<T>		iterator;
		typedef	typename	iterator::pointer		ite_pntr;

		pointer	_node;

		private:

		pointer	incremente(ite_pntr nd)
		{
			ite_pntr tmp = nd;
			ite_pntr	bis = tmp->parent;

			if (tmp->is_leaf())
				return tmp;
			if (tmp->right && !tmp->right->is_leaf())
			{
				tmp = tmp->right;
				while (tmp->left && !tmp->left->is_leaf())
					tmp = tmp->left;
				return tmp;
			}
			while (bis && tmp == bis->right)
			{
				tmp = bis;
				bis = bis->parent;
			}
			if (bis && tmp == bis->left)
				return bis;
			return _node->end;
		}

		pointer	decrement(ite_pntr nd)
		{
			ite_pntr tmp = nd;
			ite_pntr bis = tmp->parent;

			if (tmp->is_leaf())
				return tmp;
			if (tmp->left && !tmp->left->is_leaf())
			{
				tmp = tmp->left;
				while (tmp->right && !tmp->right->is_leaf())
					tmp = tmp->right;
				return tmp;
			}
			while(bis && tmp == bis->left)
			{
				tmp = bis;
				bis = bis->parent;
			}
			if (bis && tmp == bis->right)
				return bis;
			return _node->end;
		}

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor for an empty tree_iterator*/
		const_tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		const_tree_iterator(pointer x) : _node(x)
		{}

		/*Copy constructor*/
		const_tree_iterator(const_tree_iterator const& cpy) : _node(cpy._node)
		{}

		/*Destructor*/
		~const_tree_iterator()
		{}

		const_tree_iterator		&operator=(const_tree_iterator rhs)
		{
			this->_node = rhs._node;
			return *this;
		}

		/*-----------------------------------------------------------------------------------------------------------*/

		pointer	const& base() const
		{
			return this->_node;
		}

		reference	operator*() const
		{ return *this->_node; }

		const_tree_iterator&	operator++()
		{
			this->_node = incremente(const_cast<typename iterator::pointer>(_node));
			return *this;
		}

		const_tree_iterator		operator++(int)
		{
			const_tree_iterator	tmp = *this;
			this->_node = incremente(const_cast<typename iterator::pointer>(_node));
			return tmp;
		}

		const_tree_iterator&	operator--()
		{
			this->_node = decrement(const_cast<typename iterator::pointer>(_node));
			return *this;
		}

		const_tree_iterator		operator--(int)
		{
			const_tree_iterator	tmp = *this;
			this->_node = decrement(const_cast<typename iterator::pointer>(_node));
			return tmp;
		}

		bool	operator==(const himself& x) const
		{
			return _node == x._node;
		}

		bool	operator!=(const himself& x) const
		{
			return _node != x._node;
		}

	};

	template <class T>
	bool operator==(const tree_iterator<T>& lhs, const const_tree_iterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T>
	bool operator!=(const tree_iterator<T>& lhs, const const_tree_iterator<T>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
