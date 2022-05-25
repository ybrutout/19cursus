#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <memory>
# include <exception>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			/*Typedef is an alias, example: When we'll ask for a value_type, it will be the type of the template ask*/

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

		/***************\
		** CONSTRUCTOR **
		\***************/

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
			for (size_t i = 0; i < n; i++)
				this->_data[i] = val;
		}

		//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding
		//element in that range, in the same order.
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
		// {}

		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector& x) : _alloc(x._alloc), _capacity(x._capacity), _size(x._size)
		{
			this->_data = this->_alloc.allocate(this->_size);
			for (int i = 0; i < this->_size; i++)
				this->_data[i] = x._data[i];
		}

		/*****************\
		** DECONSTRUCTOR **
		\*****************/

		~vector()
		{
			this->_alloc.deallocate(this->_data, this->_capacity);
		}

		/**************\
		** OPERATOR = **
		\**************/

		vector& operator=(const vector& x)
		{
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = this->_alloc.allocate(x._capacity);
			for (size_type i = 0; i < x._size; i++)
				this->_data[i] = this->_data[i];
			return (*this);
		}

		/************\
		** CAPACITY **
		\************/

		size_type		size() const{ return this->_size; }

		size_type		max_size() const {return this->_alloc.max_size();}

		/*If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.*/
		//Refaire quand erase sera fait et insert
		// void			resize (size_type n, value_type val = value_type())
		// {
		// }

		size_type capacity() const { return this->_capacity;}

		bool empty() const
		{
			if (this->_size == 0)
				return true;
			return false;
		}

		/*Requests that the vector capacity be at least enough to contain n elements.
		If n is greater than the current vector capacity, the function causes the container to reallocate its storage
		increasing its capacity to n (or greater).In all other cases, the function call does not cause a reallocation
		and the vector capacity is not affected.This function has no effect on the vector size and cannot alter its elements.*/
		//vérifier que cela fait bien plus de place.
		void reserve (size_type n)
		{
			if (n > this->_capacity)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				pointer	tmp;
				tmp = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					tmp[i] = this->_data[i];
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = tmp;
				this->_capacity = n;
			}
			return ;
		}

		/******************\
		** ELEMENT ACCESS **
		\******************/

		reference operator[] (size_type n)
		{
			return this->_data[n];
		}

		const_reference operator[] (size_type n) const
		{
			return this->_data[n];
		}

		/*Returns a reference to the element at position n in the vector.*/
		reference at (size_type n)
		{
			if (n > this->_size)
				throw(std::out_of_range("vector::at"));
			return (this->_data[n]);
		}

		const_reference at (size_type n) const
		{
			if (n > this->_size)
				throw(std::out_of_range("vector::at_const"));
			return (this->_data[n]);
		}

		reference front()
		{
			return this->_data[0];
		}

		const_reference front() const
		{
			return this->_data[0];
		}

		reference back()
		{
			return this->_data[this->_size - 1];
		}
		const_reference back() const
		{
			return this->_data[this->_size - 1];
		}

		/*************\
		** MODIFIERS **
		\*************/

		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last)
		// {
		// }

		//Tu dois créer tes objets avec allocator.destroy / construct partout, même dans les constructeurs 
		void assign (size_type n, const value_type& val)
		{
			if (n > this->_capacity)
			{
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			this->_size = n;

		}
	};
};

#endif
