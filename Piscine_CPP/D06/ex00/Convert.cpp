/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:05:25 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 13:15:36 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _ch("0"), _in(0), _fl(0), _do(0) {}

Convert::Convert(std::string value)
{
	char	*ret;
	long	tmp;
	int		type;

	if (value.empty())
		throw Convert::Bad_input();
	if (value.size() == 1)
	{
		if (isdigit(value[0]))
		{
			this->_in	= static_cast<int>(strtol(value.c_str(), &ret, 10));
			type = 1;
		}
		else
		{
			this->_ch = value[0];
			type = 0;
		}
	}
	else
	{
		tmp = strtol(value.c_str(), &ret, 10);
		if (!ret)
		{
			if (tmp > INT_MAX || tmp < INT_MIN)
				throw Convert::Bad_input();
			else
			{
				this->_in = tmp;
				type = 1;
			}
		}
		else
		{
			double	d_tmp = strtod(value.c_str(), &ret);
			if (ret)
			{
				if (*ret == 'f')
				{
					this->_fl = static_cast<float>(d_tmp);
					type = 2;
				}
				else
					throw Convert::Bad_input();
			}
			else
			{
				this->_do = d_tmp;
				type = 3;
			}
		}
	}
	switch (type)
	{
		case 0:
			this->sinceChar();
			break;
		case 1:
			this->sinceInt();
			break;
		case 2:
			this->sinceFloat();
			break;
		case 3:
			this->sinceDouble();
			break;
		default:
			break;
	}
}

Convert::Convert(Convert const & rhs) : _ch(rhs._ch), _in(rhs._in), _fl(rhs._fl), _do(rhs._do)
{}

Convert::~Convert(){}

Convert 		&	Convert::operator=(Convert const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

int					Convert::getInt()const
{
	return this->_in;
}

char					Convert::getChar()const
{
	return this->_ch;
}

float					Convert::getFloat()const
{
	return this->_fl;
}

double					Convert::getDouble()const
{
	return this->_do;
}

void					Convert::sinceChar()
{
	
}

std::ostream	&	operator<<(std::ostream & o, Convert const & rhs)
{
	o << "char : " << rhs.getChar() << std::endl;
	o << "integer : " << rhs.getInt() << std::endl;
	return o;
}
