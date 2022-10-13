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

			T1					first;
			T2					second;

			/*Default constructor*/
			pair() : first(), second()
			{}

			/*Copy Constructor*/
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
			{}

			/*Constructor initialization*/
			pair (const first_type& a, const second_type& b) : first(a), second(b)
			{}

			/*Overload for the operator =*/
			pair& operator= (const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			}

			/*Default Deconstructor*/
			~pair()
			{}
	};

	template <class T1, class T2>
	bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	
	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class T1, class T2>
	bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	
	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class T1, class T2>
	bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{ return ( pair<T1,T2>(x,y) );}
};

#endif
