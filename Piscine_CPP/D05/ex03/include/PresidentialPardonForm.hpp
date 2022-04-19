/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:46:47 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 10:59:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&	operator=(PresidentialPardonForm const & rhs);

		void						action(Bureaucrat const &executor)const;
};

#endif
