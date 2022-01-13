/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:50:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/13 12:19:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact	*get_repertory(void);

	private:
		Contact	_repertory[8];
		int		_nbcontact;
};

#endif
