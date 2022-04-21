/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:21:59 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 17:50:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <stdlib.h>
# include <iostream>

class Base
{
	public:
		virtual ~Base(void){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
