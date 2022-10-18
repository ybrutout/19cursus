#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace	ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			/*Member Types*/
			typedef	typename	Container::value_type	value_type;
			typedef typename	Container::size_type	size_type;
			typedef				Container				container_type;

		protected:
			/*Attribut*/
			container_type			c;

		public:
			/*Default construtor*/
			explicit stack (const container_type& ctnr = container_type())
			{
				this->c = ctnr;
			}

			/*Destructor*/
			~stack()
			{}

			/*Empty : return true if the container size is zero.
			We use the empty() function of the container because in the stack definition
			it is mandatory that the container contains an empty() function.*/
			bool empty() const
			{ return this->c.empty(); }

			/*Size: return nomber of element in the vector.
			We use the size() function of the container because in the stack definition
			it is mandatory that the container contains an size() function.*/
			size_type size() const
			{ return this->c.size(); }

			/*Top: return a reference to the top element in the stack. Stack follow the rules LIFO
			(last in first out) so the top of the stack is the last element inserted into the stack.*/
			value_type& top()
			{ return this->c.back(); }

			/*Top const: return a const reference to the top element in the stack. Stack follow
			the rules LIFO (last in first out) so the top of the stack is the last element
			inserted into the stack.*/
			const value_type& top() const
			{ return this->c.back(); }

			/*Push: Insert a new element initialised to val*/
			void push (const value_type& val)
			{ this->c.push_back(val); }

			/*Pop: Remove the element on the top. So the last element insert.*/
			void pop()
			{ this->c.pop_back(); }

		private:
			template <class Type, class Ctnr>
			friend bool operator== (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);

			template <class Type, class Ctnr>
			friend bool operator!= (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);

			template <class Type, class Ctnr>
			friend bool operator<  (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);

			template <class Type, class Ctnr>
			friend bool operator<= (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);

			template <class Type, class Ctnr>
			friend bool operator>  (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);

			template <class Type, class Ctnr>
			friend bool operator>= (const stack<Type,Ctnr>& lhs, const stack<Type,Ctnr>& rhs);
	};

	/*Relationnel operator*/
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.c == rhs.c; }

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c < rhs.c); }

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c <= rhs.c); }

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c > rhs.c); }

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c >= rhs.c); }



}


#endif
