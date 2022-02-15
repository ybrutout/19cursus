/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:47:45 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/15 09:13:27 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 )
	{
		std::cout<<"Karen needs an argument to get you started:"<<std::endl;
		std::cout<<"	- debug"<<std::endl;
		std::cout<<"	- info"<<std::endl;
		std::cout<<"	- warnig"<<std::endl;
		std::cout<<"	- error"<<std::endl;
		return (1);
	}
	Karen	Karen;
	Karen.complain(argv[1]);
	return(0);
}
