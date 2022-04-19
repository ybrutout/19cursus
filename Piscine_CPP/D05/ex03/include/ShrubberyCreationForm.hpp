/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:47:53 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 10:59:25 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&	operator=(ShrubberyCreationForm const & rhs);

		virtual void				action(Bureaucrat const &executor)const;
};

#endif
