/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:00:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/13 12:12:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstring>
# include <string>

class	Contact{
	public:

		Contact(void);
		~ Contact(void);

		/*Contact	*new(void);

		static int	getnbcontact(void);

		std::string	getfirst_name(void)const;
		std::string	getlast_name(void)const;
		std::string	getnickname(void)const;
		std::string	getphone_nb(void)const;
		std::string	getdark_secret(void)const;*/

/*
		void	setfirst_name(std::string f_n);
		void	setlast_name(std::string l_n);
		void	setnickname(std::string nn);
		void	setphone_nb(std::string pn);
		void	setdark_secret(std::string ds);*///a voir si c'est utile car je set dans le new

		static int	getnbcontact(void);
		//void		setnbcontact(void);

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
		static int		_nbcontact;
};

#endif
