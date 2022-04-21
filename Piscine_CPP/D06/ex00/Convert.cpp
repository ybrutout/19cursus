/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:05:25 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 16:04:02 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _ch('0'), _in(0), _fl(0), _do(0), _type(0){}

Convert::Convert(std::string value)
{
	char	*ret;
	long	l_tmp;

	if (value.empty())
		throw Convert::Bad_input();
	if (value.size() == 1)
	{
		if (isdigit(value[0]))
		{
			this->_in	= static_cast<int>(strtol(value.c_str(), &ret, 10));
			this->_type = 1;
		}
		else
		{
			this->_ch = value[0];
			this->_type = 0;
		}
	}
	else
	{
		l_tmp = strtol(value.c_str(), &ret, 10);
		if (!ret[0])
		{
			if (l_tmp > INT_MAX || l_tmp < INT_MIN)
				throw Convert::Bad_input();
			else
			{
				this->_in = l_tmp;
				this->_type = 1;
			}
		}
		else
		{
			double	d_tmp = strtod(value.c_str(), &ret);
			if (ret[0])
			{
				if (ret[0] == 'f')
				{
					this->_fl = static_cast<float>(d_tmp);
					this->_type = 2;
				}
				else
					throw Convert::Bad_input();
			}
			else
			{
				this->_do = d_tmp;
				this->_type = 3;
			}
		}
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
	switch (this->_type)
	{
	case 0:
		return static_cast<int>(this->_ch);
	case 1:
		return this->_in;
	case 2:
		if (isnan(this->_fl) || isinf(this->_fl)
			|| this->_fl > INT_MAX || this->_fl < INT_MIN)
			throw Convert::Impossible();
		else
			return static_cast<int>(this->_fl);
	case 3:
		if (isnan(this->_do) || isinf(this->_do)
			|| this->_do > INT_MAX || this->_do < INT_MIN)
			throw Convert::Impossible();
		else
			return static_cast<int>(this->_do);
	default :
		break;
	}
	return 0;
}

char					Convert::getChar()const
{
	switch (this->_type)
	{
		case 0:
			return this->_ch;
		case 1:
			if (this->_in < 0 || this->_in > 126)
				throw Convert::Impossible();
			if (this->_in >= 0 && this->_in <= 31)
				throw Convert::Non_displayable();
			else
				return static_cast<char>(this->_in);
		case 2:
			if (this->_fl < 0 || this->_fl > 126 \
			|| isnan(this->_fl) || isinf(this->_fl))
				throw Convert::Impossible();
			if (this->_fl >= 0 && this->_fl <= 31)
				throw Convert::Non_displayable();
			else
				return static_cast<char>(this->_fl);
		case 3:
			if (this->_do < 0 || this->_do > 126 \
			|| isnan(this->_do) || isinf(this->_do))
				throw Convert::Impossible();
			if (this->_do >= 0 && this->_do <= 31)
				throw Convert::Non_displayable();
			else
				return static_cast<char>(this->_do);
		default :
			break;
	}
	return '0';
}

float					Convert::getFloat()const
{
	switch (this->_type)
	{
		case 0:
			return static_cast<float>(this->_ch);
		case 1:
			return static_cast<float>(this->_in);
		case 2:
			return this->_fl;
		case 3:
			return static_cast<float>(this->_do);
		default :
			break;
	}
	return 0;
}

double					Convert::getDouble()const
{
	switch (this->_type)
	{
		case 0:
			return static_cast<double>(this->_ch);
		case 1:
			return static_cast<double>(this->_in);
		case 2:
			return static_cast<double>(this->_fl);
		case 3:
			return this->_do;
		default :
			break;
	}
	return 0;
}

std::ostream	&	operator<<(std::ostream & o, Convert const & rhs)
{
	try
	{
		o << "char : " << rhs.getChar() << std::endl;
	}
	catch (const std::exception& e)
	{
		o << e.what() << std::endl;
	}
	try
	{
		o << "integer : " << rhs.getInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		o << e.what() << std::endl;
	}
	o << "float : " << rhs.getFloat() << "f" << std::endl;
	o << "double : " << rhs.getDouble() << std::endl;
	return o;
}
