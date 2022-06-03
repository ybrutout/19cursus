#ifndef	VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <exception>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "type_traits.hpp"

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			/*Typedef is an alias, example: When we'll ask for a value_type, it will be the type of the template ask*/

			typedef				T													value_type;
			typedef				Alloc												allocator_type;
			typedef typename	allocator_type::reference							reference;
			typedef typename	allocator_type::const_reference						const_reference;
			typedef typename	allocator_type::pointer								pointer;
			typedef typename	allocator_type::const_pointer						const_pointer;
			typedef typename	ft::random_access_iterator<value_type>				iterator;
			typedef typename	ft::random_access_iterator<const value_type>		const_iterator;
			typedef typename	ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename	ft::reverse_iterator<const iterator>				const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef				size_t												size_type;

		private:

			pointer					_data;
			allocator_type			_alloc;
			size_type				_capacity;
			size_type				_size;

		public:

		/***************\
		** CONSTRUCTOR **
		\***************/

		/*Constructs an empty container with the given allocator alloc.*/
		explicit vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _capacity(0), _size(0) {}

		/*Constructs a container with n elements. Each element is a copy of val.
		Rem : pas de gestion pour savoir si l'allocation de mémoire a été faite proprement ou non car std::allocator::allocate le fait lui même.*/
		explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n)
		{
			if (n < 0)
				throw(std::out_of_range("vector"));
			this->_data = this->_alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(&this->_data[i], val);
		}

		/*Constructs the container with the contents of the range [first, last).*/
		template< class InputIt >
		vector( InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = NULL) : _alloc(alloc)
		{
			size_type	tmp_size = 0;
			for (InputIt it = first; it != last; it++)
				tmp_size++;
			this->_size = tmp_size;
			this->_capacity = tmp_size;
			this->_data = this->_alloc.allocate(this->_size);
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], *first++);
		}

		/*Constructs a container with a copy of each of the elements in x, in the same order.*/
		vector (const vector& x) : _alloc(x._alloc), _capacity(x._capacity), _size(x._size)
		{
			this->_data = this->_alloc.allocate(this->_size);
			for (int i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], x._data[i]);
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
				this->_alloc.construct(this->_data[i], x._data[i]);
			return (*this);
		}

		/************\
		** ITERATOR **
		\************/

		/*Return an iterator to the first element.*/
		iterator begin()
		{ return this->_data;}

		/*Return an iterator to the first element*/
		const_iterator begin() const
		{ return this->_data;}

		/*Return an iterator to the element folowing the last element.*/
		iterator end()
		{ return (this->_data + this->_size); }

		/*Return a const iterator to the element folowing the last element.*/
		const_iterator end() const
		{return (this->_data + this->_size); }

		/*Return a reverse iterator to the first element for a reverse_iterator so to the last element.*/
		reverse_iterator rbegin()
		{ return (this->_data + this->_size - 1); }

		/*Return a const reverse iterator to the first element for a reverse_iterator so to the last element.*/
		const_reverse_iterator rbegin() const
		{ return (this->_data + this->_size - 1); }

		/*Return a reverse_iterator to the element folowing the last element for a reverse_iterator so to the element before the first element.*/
		reverse_iterator rend()
		{ return (this->_data - 1); }

		/*Return a const reverse_iterator to the element folowing the last element
		for a reverse_iterator so to the element before the first element.*/
		const_reverse_iterator rend() const
		{ return (this->_data - 1); }

		/************\
		** CAPACITY **
		\************/

		/*Return the number of element present in the vector. It's not the same than the capacity.*/
		size_type		size() const{ return this->_size; }

		/*return the maximum number than the system accept or the library.*/
		size_type		max_size() const {return this->_alloc.max_size();}

		/*If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.*/
		//Refaire quand erase sera fait et insert
		// void			resize (size_type n, value_type val = value_type())
		// {
		// }

		/*Return the actualy capacity in the vector.*/
		size_type capacity() const { return this->_capacity;}

		/*Return true if the vector is empty.*/
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

		/*Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument is an
		iterator into *this.*/
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			InputIterator n = last - first + 1;
			if (n > this->_capacity)
			{
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			else
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_data[i]);
			}
			this->_size = n;
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(this->_data[i], first++);
		}

		/*(Fill version) Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		The new contents are n elements, each initialized to a copy of val.*/
		void assign (size_type n, const value_type& val)
		{
			if (n > this->_capacity)
			{
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			else
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_data[i]);
			}
			this->_size = n;
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(&this->_data[i], val);
		}

		/*Adds a new element at the end of the vector, after its current last element. The content of val is copied
		(or moved) to the new element.*/
		void push_back (const value_type& val)
		{
			if (this->_size == this->_capacity)
			{
				pointer	tmp = this->_alloc.allocate(this->_size * 2);
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&tmp[i], this->_data[i]);
					this->_alloc.destroy(&this->_data[i]);
				}
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = tmp;
				this->_capacity = this->_size * 2;
			}
			this->_alloc.construct(&this->_data[this->_size], val);
			this->_size++;
		}

		/*Removes the last element in the vector, effectively reducing the container size by one.*/
		/*There no check if is an empty vector and the size is decrement so its a big number.*/
		void pop_back()
		{
			if (this->_size > 0)
				this->_alloc.destroy(&this->_data[this->_size - 1]);
			this->_size--;
		}

		// single element (1)
		// iterator insert (iterator position, const value_type& val);
		// fill (2)
    	// void insert (iterator position, size_type n, const value_type& val);
		// range (3)
		// template <class InputIterator>
    	// void insert (iterator position, InputIterator first, InputIterator last);
		//need iterator

		//need iterator too
		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		void swap (vector& x)
		{
			vector	tmp(x);

			x._alloc = this->_alloc;
			x._alloc.deallocate(x._data, x._capacity);
			x._data = x._alloc.allocate(this->_capacity);
			x._size = this->_size;
			for (size_t i = 0; i < x._size; i++)
				x._alloc.construct(&x._data[i], this->_data[i]);
			this->_alloc = tmp->_alloc;
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = this->_alloc.allocate(tmp._capacity);
			this->_size= tmp->_size;
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], tmp->_data[i]);
		}

		/*Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.*/
		void clear()
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_data[i]);
			this->_size = 0;
		}

		/*************\
		** ALLOCATOR **
		\*************/

		/*Returns a copy of the allocator object associated with the vector.*/
		allocator_type get_allocator() const
		{ return this->_alloc; }
	};
};

#endif
