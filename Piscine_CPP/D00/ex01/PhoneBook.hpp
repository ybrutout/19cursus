/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:50:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/14 17:08:42 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"
# include <cstdlib>
# include <unistd.h>

class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact		*get_repertory(void);

		void		add_contact(Contact *nw);
		void		show_contact(void);

		int 		get_nbcontact(void)const;

	private:
		Contact	_repertory[8];
		int		_nbcontact;

		void	have_ten(std::string buff);
		int		strtoint(const char *str);
};

#endif
