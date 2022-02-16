/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:00:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/16 13:37:01 by ybrutout         ###   ########.fr       */
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

		int	add_contact(void);

		std::string	get_first_name(void)const;
		std::string	getlast_name(void);
		std::string	getnickname(void);
		std::string	getphone_nb(void);
		std::string	getdark_secret(void);

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
};

#endif
