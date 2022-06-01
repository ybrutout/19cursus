#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace	ft
{
	template <typename T>
	class iterator
	{
		public:
		typedef		int									difference_type;
		typedef		T									value_type;
		typedef		T*									pointer;
		typedef		T&									reference;
		typedef		std::random_access_iterator_tag		iterator_category;

		private:
		pointer		_p;

		public:
		/*----------------------------------------Canonical Form-----------------------------------------------------*/
		Iterator(){}

		Iterator(pointer p) {this->_p = p;}

		// Iterator (Iterator )
		// Iterator (const Iterator)

		~Iterator() {}

		iterator&	operator=(const iterator& it)
		{
			this->_p = it._p;
			return (*this);
		}
		/*-----------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------Operator--------------------------------------------------------*/
		/*Return a reference to the element pointed by the itreator*/
		reference	operator*() const
		{
			return *this->_p;
		}

		iterator	operator+(difference_type n) const
		{
			pointer	tmp = this->_p + n;
			return tmp;
		}

		iterator&	operator++()
		{
			++this->_p;
			return *this;
		}

		iterator	operator++(int)
		{
			return this->_p++;
		}

		iterator&	operator+=(difference_type n)
		{
			this->_p += n;
			return *this;
		}

		iterator operator-(difference_type n) const
		{
			pointer tmp = this->_p - n;
			return tmp;
		}

		iterator& operator--()
		{
			--this->_p;
		}
		iterator  operator--(int);


	};
};

#endif
