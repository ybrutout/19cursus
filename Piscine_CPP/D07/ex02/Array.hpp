/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:57 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 16:53:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>

class Array
{
	public:
		Array() : _n(0), _array(new T[0]) {}
		Array(int n)
		{
			if (n < 0)
				throw Array::BadIndex();
			this->_n = n;
			this->_array = new T[n];
		}
		Array(Array const & cpy)
		{
			this->_n = cpy._n;
			this->_array = new T[cpy._n];
			for (int i = 0; i < this->_n; i++)
				this->_array[i] = cpy._array[i];
		}
		~Array()
		{
			delete [] this->_array;
		}

		Array	&		operator=(Array const rhs)
		{
			delete this->_array;
			this->_n = rhs._n;
			this->_array = new T[this->_n];
			for (int i = 0; i < this->_n; i++)
				this->_array[i] = rhs._array[i];
			return *this;
		}
		T		&		operator[](int index)
		{
			if (index >= this->_n || index < 0)
				throw Array::BadIndex();
			return (this->_array[index]);
		}
		int	size()const {return this->_n;}

		class BadIndex : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "This index doesn't exist.";
				}
		};

	private:
		int				_n;
		T				*_array;
};

#endif
