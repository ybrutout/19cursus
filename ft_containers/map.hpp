#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include "red_black_tree.hpp"
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include <cstdlib>

namespace ft
{
	template < class Key, class T,class Compare = ft::less<Key>,class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
		//Je comprends le principe, je comprends pas encore l'utilité
		// class	value_compare : std::binary_function<pair<const Key, T>, pair<const Key, T>, bool>
		// {
		// 	friend class map<Key, T, Compare, Alloc>;
		// 	protected:
		// 		Compare _comp;
		// 		value_compare(Compare c) : _comp(c) {return ;}

		// 	public:
		// 		bool operator()(const pair<const Key, T>& x, const pair<const Key, T>& y) const { return _comp(x.first, y.first); }
		// };

		typedef				Key																	key_type;
		typedef				T																	mapped_type;
		typedef				ft::pair<key_type, mapped_type>										value_type;
		typedef				Compare																key_compare;
		typedef				Alloc																allocator_type;
		typedef typename	allocator_type::reference											reference;
		typedef typename	allocator_type::const_reference										const_reference;
		typedef typename	allocator_type::pointer												pointer;
		typedef typename	allocator_type::const_pointer										const_pointer;

		private:
		typedef typename	ft::RBTree<key_type, mapped_type, key_compare, allocator_type>		tree_type;

		public:
		typedef typename	tree_type::iterator													iterator;
		typedef typename	tree_type::const_iterator											const_iterator;
		typedef	typename	tree_type::reverse_iterator											reverse_iterator;
		typedef	typename	tree_type::const_reverse_iterator									const_reverse_iterator;
		typedef				ptrdiff_t															difference_type;
		typedef				size_t																size_type;

		private:
		tree_type		_tree;
		allocator_type	_alloc;

		public:
		///TO DO
		/// A enlever
		tree_type	*get_tree()
		{
			// tree_type tmp(_tree); Faire un constructeur par de2faut si je veux une réelle copie.
			return &_tree;
		}
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor*/
		explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
		: _tree(comp, alloc), _alloc(alloc)
		{}

		/*Range constructor*/
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _tree(comp, alloc), _alloc(alloc)
		{
			insert(first, last);
		}

		map(const map& x) : _tree(x._tree), _alloc(x.get_allocator())
		{}

		/*Deconstructor*/
		~map()
		{}

		map& operator=(const map& x)
		{
			clear();
			insert(x.begin(), x.end());
			return *this;
		}
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Iterators-------------------------------------------------------*/
		iterator	begin()
		{
			if (empty())
				return iterator(_tree.get_the_end());
			return iterator(_tree.RBTMinVal());
		}

		const_iterator begin() const
		{
			if (empty())
				return const_iterator(_tree.get_the_end());
			return const_iterator(_tree.RBTMinVal());
		}

		iterator	end()
		{
			return iterator(_tree.get_the_end());
		}

		const_iterator	end() const
		{
			return const_iterator(_tree.get_the_end());
		}

		reverse_iterator rbegin()
		{
			reverse_iterator tmp(_tree.get_the_end());
			return tmp;
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(_tree.get_the_end());
		}

		reverse_iterator rend()
		{
			if (empty())
				return reverse_iterator(_tree.get_the_end());
			return reverse_iterator(_tree.RBTMinVal());
		}

		const_reverse_iterator rend() const
		{
			if (empty())
				return const_reverse_iterator(_tree.get_the_end());
			return reverse_iterator(_tree.RBTMinVal());
		}
		/*-----------------------------------------------------------------------------------------------------------*/

		/*----------------------------------------Element-Access-----------------------------------------------------*/

		mapped_type& operator[](const key_type& k)
		{
			typename tree_type::node	*tmp = _tree.find_the_value(k);
			if (tmp != _tree.get_the_end())
				return tmp->value.second;
			insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
			tmp = _tree.find_the_value(k);
			return tmp->value.second;
		}

		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Modifiers-------------------------------------------------------*/
		pair<iterator,bool>	insert(const value_type& val)
		{
			return _tree.insert(val);
		}

		iterator	insert(iterator position, const value_type& val)
		{
			(void)position;
			return _tree.insert(val).first;
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_tree.insert(*first);
				first++;
			}
		}

		//Je sais pas si ca va car je supprime un element qui a la meme clé que l'iterateur qu'on m'a envoye mais si c'est un autre ...
		void	erase(iterator position)
		{
			_tree.to_delete((*position).first);
		}

		//erase fonctionne pas je sais pas pourquoi
		// 	second.get_tree()->print();
		// for (size_t i = 0; i < 15; i++)
		// 	second.erase(i);
		// second.get_tree()->print();
		size_type	erase(const key_type& k)
		{
			if (_tree.find_the_value(k) == _tree.get_the_end())
				return 0;
			_tree.to_delete(k);
			return 1;
		}

		//meme probleme qu'avec le erase iterator
		void	erase(iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first;
				first++;
				_tree.to_delete((*tmp).first);
			}
		}

		void	swap (map& x)
		{
			_tree.swap(&x._tree);
		}

		void	clear()
		{
			erase(begin(), end());
		}

		/*-----------------------------------------------------------------------------------------------------------*/
		/*-------------------------------------------Capacity--------------------------------------------------------*/

		bool empty() const
		{
			if (_tree.get_size() > 0)
				return false;
			return true;
		}

		size_type size() const
		{
			return _tree.get_size();
		}

		size_type max_size() const
		{
			return _alloc.max_size();
		}
		/*-----------------------------------------------------------------------------------------------------------*/
		/*-------------------------------------------Opérations------------------------------------------------------*/

		iterator find(const key_type& k)
		{
			return iterator(_tree.find_the_value(k));
		}

		const_iterator find(const key_type& k) const
		{
			return const_iterator(_tree.find_the_value(k));
		}

		size_type count(const key_type& k) const
		{
			if (_tree.find_the_value(k) == _tree.get_the_end())
				return 0;
			return 1;
		}

		iterator		lower_bound(const key_type& k)
		{
			return iterator(_tree.LowerBound(k));
		}

		const_iterator	lower_bound(const key_type& k) const
		{
			return const_iterator(_tree.LowerBound(k));
		}

		iterator		upper_bound(const key_type& k)
		{
			return iterator(_tree.upperBound(k));
		}
		const_iterator	upper_bound(const key_type& k) const
		{
			return const_iterator(_tree.upperBound(k));
		}

		/*-----------------------------------------------------------------------------------------------------------*/
		/*-------------------------------------------Allocator-------------------------------------------------------*/

		allocator_type get_allocator() const
		{
			allocator_type	tmp(_tree.get_alloc());
			return tmp;
		}

		/*-----------------------------------------------------------------------------------------------------------*/
	};

	/*-----------------------------------------No Member Function----------------------------------------------------*/

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		if (!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())))
			return false;
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
	/*---------------------------------------------------------------------------------------------------------------*/
};

#endif
