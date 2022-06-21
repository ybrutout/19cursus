#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace	ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef		T1		first_type;
			typedef		T2		second_type;

			T1					_first;
			T2					_second;

			/*Default constructor*/
			pair() : _first(), _second()
			{}

			/*Copy Constructor*/
			template<class U, class V>
			pair (const pair<U,V>& pr) : _first(pr._first), _second(pr._second)
			{}

			/*Constructor initialization*/
			pair (const first_type& a, const second_type& b) : _first(a), _second(b)
			{}

			/*Overload for the operator ==*/
			pair& operator= (const pair& pr)
			{
				this->_first = pr._first;
				this->_second = pr._second;
				return *this;
			}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs._first == rhs._first && lhs._second == rhs._second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs._first < rhs._first || (!(lhs._first < rhs._second) && lhs._second < rhs._second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs;}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }
};

#endif
