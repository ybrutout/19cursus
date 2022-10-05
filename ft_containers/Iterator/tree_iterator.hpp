#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		typedef				T					node;
		typedef	typename	T::value_type_ptr	pointer;
		typedef	typename	T::value_type_ref	reference;
		typedef				node*				node_ptr;
		typedef				tree_iterator<T>	himself;

		node_ptr	_node;

		private:

		node_ptr	biggest()
		{
			node_ptr	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->right->is_leaf())
			{
				tmp = tmp->right;
			}
			return tmp;
		}

		node_ptr	smallest()
		{
			node_ptr	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->left->is_leaf())
				tmp = tmp->left;
			return tmp;
		}

		node_ptr	incremente()
		{
			node_ptr tmp = this->_node;
			node_ptr	bis = tmp->parent;

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

		node_ptr	decrement()
		{
			node_ptr tmp = _node;
			node_ptr bis = tmp->parent;

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
		tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		tree_iterator(node_ptr x) : _node(x)
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

		node_ptr	const& base() const
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
		typedef	typename	T::const_value_type_ptr	pointer;
		typedef	typename	T::const_value_type_ref	reference;
		typedef	const		node*					node_ptr;
		typedef				const_tree_iterator<T>	himself;
		typedef				tree_iterator<T>		iterator;
		typedef	typename	iterator::node_ptr		ite_pntr;

		node_ptr	_node;

		private:

		node_ptr	biggest()
		{
			node_ptr	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->right->is_leaf())
				tmp = tmp->right;
			return tmp;
		}

		node_ptr	smallest()
		{
			node_ptr	tmp = _node;

			while (tmp->parent)
				tmp = tmp->parent;
			while (!tmp->left->is_leaf())
				tmp = tmp->left;
			return tmp;
		}

		node_ptr	incremente(ite_pntr nd)
		{
			ite_pntr tmp = nd;
			ite_pntr	bis = tmp->parent;

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

		node_ptr	decrement(ite_pntr nd)
		{
			ite_pntr tmp = nd;
			ite_pntr bis = tmp->parent;

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
		const_tree_iterator() : _node(NULL)
		{}

		/*Constructor with a value*/
		const_tree_iterator(node_ptr x) : _node(x)
		{}

		/*Copy constructor*/
		const_tree_iterator(const_tree_iterator const& cpy) : _node(cpy._node)
		{}

		const_tree_iterator(iterator const& cpy) : _node(cpy._node)
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

		node_ptr	const& base() const
		{
			return this->_node;
		}

		typename T::const_value_type_ref	operator*() const
		{
			return _node->value;
		}

		const_tree_iterator&	operator++()
		{
			this->_node = incremente(const_cast<typename iterator::node_ptr>(_node));
			return *this;
		}

		const_tree_iterator		operator++(int)
		{
			const_tree_iterator	tmp = *this;
			this->_node = incremente(const_cast<typename iterator::node_ptr>(_node));
			return tmp;
		}

		const_tree_iterator&	operator--()
		{
			this->_node = decrement(const_cast<typename iterator::node_ptr>(_node));
			return *this;
		}

		const_tree_iterator		operator--(int)
		{
			const_tree_iterator	tmp = *this;
			this->_node = decrement(const_cast<typename iterator::node_ptr>(_node));
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
