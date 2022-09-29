#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
		typedef 			Iterator										iterator_type;
		typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename	iterator_traits<Iterator>::value_type			value_type;
		typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	iterator_traits<Iterator>::pointer				pointer;
		typedef typename	iterator_traits<Iterator>::reference			reference;

		protected:
		iterator_type			_current;

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		/*Default constructor*/
		reverse_iterator()
		{this->_current = NULL;}

		/*Copy constructor with an original iterator*/
		explicit reverse_iterator( iterator_type x ) : _current(x)
		{
			std::cout << "x == " << x->first << std::endl;
		}

		/*Copy constructor with an other revrese_iterator*/
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) : _current(other.base())
		{}

		operator reverse_iterator<const Iterator>() const
		{ return this->_current; }

		/*Deconstructor*/
		~reverse_iterator()
		{}

		// /*Overload operator for assignement*/
		// reverse_iterator&	operator=(const reverse_iterator& it)
		// {
		// 	this->_current = it._current;
		// 	return *this;
		// }
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Operator--------------------------------------------------------*/
		/*Return de underlying base iterator*/
		iterator_type base() const
		{return this->_current;}

		/*Return the reference to the element.*/
		reference operator*() const
		{
			iterator_type	tmp = this->_current;
			--tmp;
			return *tmp;
		}

		/*Return the pointer to the current element.*/
		pointer operator->() const
		{ return &(operator*()); }

		/*Returns a reference to the element at specified relative location.*/
		reference	operator[]( difference_type n ) const
		{ return *(*this + n); }
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Advances or decrements operator---------------------------------*/
		/*Pre-increment by one*/
		reverse_iterator& operator++()
		{
			--this->_current;
			return *this;
		}

		/*Pre-decrement by one*/
		reverse_iterator& operator--()
		{
			++this->_current;
			return *this;
		}

		/*Post-increment by one*/
		reverse_iterator operator++( int )
		{
			reverse_iterator tmp = *this;
       		--this->_current;
        	return tmp;
		}

		/*Post-decrement by one*/
		reverse_iterator operator--( int )
		{
			reverse_iterator tmp = *this;
			++this->_current;
			return tmp;
		}

		/*Returns an iterator which is advanced by n position */
		reverse_iterator operator+( difference_type n ) const
		{ return reverse_iterator(this->_current - n);}

		/*Return an iterator which is advanced by -n position*/
		reverse_iterator operator-( difference_type n ) const
		{ return reverse_iterator(this->_current + n);}

		difference_type		operator-(reverse_iterator const & b)
		{
			return (b._current.base() - this->_current.base());
		}

		/*Advances the iterator by n position*/
		reverse_iterator& operator+=( difference_type n )
		{
			this->_current -= n;
			return *this;
		}

		/*Advances the iterator by -n position*/
		reverse_iterator& operator-=( difference_type n )
		{
			this->_current += n;
			return *this;
		}
	};
	/*------------------------------------------No member functions--------------------------------------------------*/

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{return lhs.base() == rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{return lhs.base() != rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{ return lhs.base() > rhs.base(); }

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{ return lhs.base() >= rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{return lhs.base() < rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{return lhs.base()<= rhs.base();}

	template< class Iter >
	reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{ return reverse_iterator<Iter>(it.base() - n);}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
	{ return rhs.base() - lhs.base();}
};
#endif
