#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
		typedef typename	ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename	ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
		typedef typename	ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename	ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename	ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		protected:
		pointer		_p;

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		Random_access_iterator() : _p() {}

		Random_access_iterator(pointer p) : _p(p) {}

		Random_access_iterator(const random_access_iterator& other) : _p(other._p)

		~Random_access_iterator() {}

		Random_access_iterator&	operator=(const random_access_iterator& it)
		{
			this->_p = it._p;
			return (*this);
		}
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Operator--------------------------------------------------------*/

		pointer const& base() const
		{
			return this->_p;
		}

		/*Return a reference to the element pointed by the itreator*/
		reference	operator*() const
		{
			return *this->_p;
		}

		random_access_iterator	operator+(difference_type n) const
		{
			pointer	tmp = this->_p + n;
			return tmp;
		}

		random_access_iterator&	operator++()
		{
			++this->_p;
			return *this;
		}

		random_access_iterator	operator++(int)
		{
			return this->_p++;
		}

		random_access_iterator&	operator+=(difference_type n)
		{
			this->_p += n;
			return *this;
		}

		random_access_iterator operator-(difference_type n) const
		{
			pointer tmp = this->_p - n;
			return tmp;
		}

		random_access_iterator& operator--()
		{
			--this->_p;
			return *this;
		}

		random_access_iterator  operator--(int)
		{
			return this->_p--;
		}

		random_access_iterator& operator-=(difference_type n)
		{
			this->_p -= n;
			return *this;
		}

		pointer operator->() const
		{
			return this->_p;
		}

		reference operator[](difference_type n) const
		{
			pointer	tmp = this->_p + n;
			return *tmp;
		}
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs)
	{
		return !(lhs > rhs);
	}

	template <class Iterator>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n,const random_access_iterator<Iterator>& it)
	{
		return it + n;
	}

	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator- (const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs)
	{
		return lhs.base() - rhs.base();
	}
};

#endif
