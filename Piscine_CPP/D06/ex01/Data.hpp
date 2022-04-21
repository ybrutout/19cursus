/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:49 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 17:03:30 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:
		Data();
		Data(Data const & cpy);
		Data(std::string name);
		~Data();

		Data		&	operator=(Data const & rhs);

		std::string		getName()const;
	private:
		std::string		_name;
};

uintptr_t	serialize(Data* ptr);
Data	*	deserialize(uintptr_t raw);

#endif
