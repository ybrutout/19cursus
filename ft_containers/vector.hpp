#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <memory>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			typedef		T			value_type;
			typedef		Alloc		allocator_type;
			typedef 	T&			reference;
			typedef 	const T&	const_reference;
			typedef 	T*			pointer;
			typedef 	const T*	const_pointer;
			//iterator
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator
			//difference_type
			typedef		size_t		size_type;

		private:

			pointer					_data;
			allocator_type			_alloc;
			size_type				_capacity;
			size_type				_size;

		public:

		/**************\
		**CONSTRUCTEUR**
		\**************/

		//Default constructor, constructs an empty container, with any element.
		explicit vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _capacity(0), _size(0)
		{}

		//Constructs a container with n elements. Each element is a copy of val.
		//Rem : pas de gestion pour savoir si l'allocation de mémoire a été faite proprement ou non car std::allocator::allocate le fait lui même.
		explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n)
		{
			if (n < 0)
				throw(std::out_of_range("vector"));
			this->_data = this->_alloc.allocate(n);
			for (int i = 0; i < n; i++)
				this->_data[i] = val;
		}

		//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding
		//element in that range, in the same order.
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
		{}

		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector& x) : _alloc(x._alloc), _capacity(x._capacity), _size(x._size)
		{
			this->_data = this->_alloc.allocate(this->_size);
			for (int i = 0; i < this->_size; i++)
				this->_data[i] = x._data[i];
		}


	};
};

#endif
