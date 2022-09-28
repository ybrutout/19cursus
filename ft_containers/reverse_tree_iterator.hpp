#ifndef REVERSE_TREE_ITERATOR_HPP
# define REVERSE_TREE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class reverse_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		typedef				T							node;
		typedef				node*						pointer;
		typedef				node&						reference;
		typedef				reverse_tree_iterator<T>	himself;

		pointer	_node;

		private:

		pointer	biggest()
		{
			pointer	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->right->is_leaf())
				tmp = tmp->right;
			return tmp;
		}

		pointer	smallest()
		{
			pointer	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->left->is_leaf())
				tmp = tmp->left;
			return tmp;
		}

		pointer	decremente()
		{
			pointer tmp = this->_node;
			pointer	bis = tmp->parent;

			if (tmp->is_leaf())
				return smallest();
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

		pointer	incremente()
		{
			pointer tmp = _node;
			pointer bis = tmp->parent;

			if (tmp->is_leaf())
				return biggest();
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
		reverse_tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		reverse_tree_iterator(pointer x) : _node(x)
		{}

		/*Copy constructor*/
		reverse_tree_iterator(reverse_tree_iterator const& cpy) : _node(cpy._node)
		{}

		/*Destructor*/
		~reverse_tree_iterator()
		{}

		reverse_tree_iterator		&operator=(reverse_tree_iterator rhs)
		{
			this->_node = rhs._node;
			return *this;
		}
		/*-----------------------------------------------------------------------------------------------------------*/

		pointer	const& base() const
		{
			return this->_node;
		}

		typename T::value_type_ptr operator->() const
		{
			typename T::value_type_ptr val = &_node->value;
			return val;
		}

		typename T::value_type_ref	operator*() const
		{
			typename T::value_type_ref val = _node->value;
			return val;
		}

		reverse_tree_iterator&	operator++()
		{
			this->_node = incremente();
			return *this;
		}

		reverse_tree_iterator	operator++(int)
		{
			reverse_tree_iterator	tmp = *this;
			this->_node = incremente();
			return tmp;
		}

		reverse_tree_iterator&	operator--()
		{
			this->_node = decremente();
			return *this;
		}

		reverse_tree_iterator	operator--(int)
		{
			reverse_tree_iterator	tmp = *this;
			this->_node = decremente();
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
	class const_reverse_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		typedef				T						node;
		typedef	const		node*					pointer;
		typedef	const		node&					reference;
		typedef				const_reverse_tree_iterator<T>	himself;
		typedef				tree_iterator<T>		iterator;
		typedef	typename	iterator::pointer		ite_pntr;

		pointer	_node;

		private:

		pointer	decrement(ite_pntr nd)
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

		pointer	increment(ite_pntr nd)
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
		const_reverse_tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		const_reverse_tree_iterator(pointer x) : _node(x)
		{}

		/*Copy constructor*/
		const_reverse_tree_iterator(const_reverse_tree_iterator const& cpy) : _node(cpy._node)
		{}

		/*Destructor*/
		~const_reverse_tree_iterator()
		{}

		const_reverse_tree_iterator		&operator=(const_reverse_tree_iterator rhs)
		{
			this->_node = rhs._node;
			return *this;
		}

		/*-----------------------------------------------------------------------------------------------------------*/

		pointer	const& base() const
		{
			return this->_node;
		}

		typename T::const_value_type_ref	operator*() const
		{
			return _node->value;
		}
		const_reverse_tree_iterator&	operator++()
		{
			this->_node = incremente(const_cast<typename iterator::pointer>(_node));
			return *this;
		}

		const_reverse_tree_iterator		operator++(int)
		{
			const_reverse_tree_iterator	tmp = *this;
			this->_node = incremente(const_cast<typename iterator::pointer>(_node));
			return tmp;
		}

		const_reverse_tree_iterator&	operator--()
		{
			this->_node = decrement(const_cast<typename iterator::pointer>(_node));
			return *this;
		}

		const_reverse_tree_iterator		operator--(int)
		{
			const_reverse_tree_iterator	tmp = *this;
			this->_node = decrement(const_cast<typename iterator::pointer>(_node));
			return tmp;
		}

		typename T::const_value_type_ptr operator->() const
		{
			return &_node->value;
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
	bool operator==(const reverse_tree_iterator<T>& lhs, const const_reverse_tree_iterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T>
	bool operator!=(const reverse_tree_iterator<T>& lhs, const const_reverse_tree_iterator<T>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
