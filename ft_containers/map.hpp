#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include "red_black_tree.hpp"
# include "pair.hpp"

namespace ft
{
	template < class Key, class T,class Compare = ft::less<Key>,class Alloc = std::allocator<ft::pair<const Key,T> > >
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
		typedef typename	ft::RBTree<key_type, mapped_type, key_compare, allocator_type>		tree_type;

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
		///TO DO
		/// A enlever
		tree_type	get_tree()
		{
			// tree_type tmp(_tree); Faire un constructeur par de2faut si je veux une réelle copie.
			return _tree;
		}
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor*/
		explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
		{}

		/*Range constructor*/
		//TO DO : The insertion first before the range
		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		// : _tree(comp, alloc)
		// {
		// 	while (first != last)
		// 	{
		// 		this->_tree.insert(*first);
		// 		first++;
		// 	}
		// }

		// /*Copy constructor*/
		// TO DO : Insertion
		// map (const map& x) : _tree(x._tree)
		// {}

		/*Deconstructor*/
		~map()
		{}

		// map& operator= (const map& x)
		// {}
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Iterators-------------------------------------------------------*/

		iterator	begin()
		{
			iterator	it(_tree.RBTMinVal());
			return it;
		}

		//TO DO
		//const_iterator begin() const;

		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Modifiers-------------------------------------------------------*/
		pair<iterator,bool> insert(const value_type& val)
		{
			return _tree.insert(val);
		}

		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			return _tree.insert(val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_tree.insert(first._node->value);
				first++;
			}
		}

		//Je sais pas si ca va car je supprime un element qui a la meme clé que l'iterateur qu'on m'a envoye mais si c'est un autre ...
		void erase (iterator position)
		{
			_tree.to_delete((*position).value.first);
		}

		size_type erase (const key_type& k)
		{
			return _tree.to_delete(k);
		}

		//meme probleme qu'avec el erase iterator
		void erase (iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first;
				first++;
				_tree.to_delete((*tmp).value.first);
			}
		}

		void swap (map& x)
		{
			_tree.swap(x._tree);
		}
		/*-----------------------------------------------------------------------------------------------------------*/
	};
};

#endif
