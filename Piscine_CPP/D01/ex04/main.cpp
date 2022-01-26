/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:01:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/26 11:26:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
# include <string>

int		main(int argc, char **argv)
{
	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout<<"The program takes as parameters the filename, a string 1 and a string 2. Like : "<<std::endl;
		std::cout<<"	./replace filename s1 s2"<<std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::ifstream	ifs(filename);
	if (!ifs)
	{
		std::cout<<"The file doesn't exist or the permissions are closed"<<std::endl;
		return (0);
	}
	std::ofstream out(filename += ".replace");
	ifs.seekg(0,ifs.end);
	int lenght = ifs.tellg();
	ifs.seekg(0,ifs.beg);
	char * buff = new char[lenght];
	ifs.read(buff, lenght);
	std::string buffer = buff;
	for(size_t i = buffer.find(s1); i != std::string::npos; i = buffer.find(s1))
	{
		buffer.erase(i, s1.length());
		buffer.insert(i, s2);
	}
	buffer.begin();
	out << buffer;
	out.close();
	ifs.close();
	return (0);
}
