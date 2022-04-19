/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:45:06 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 10:59:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&	operator=(RobotomyRequestForm const & rhs);

		void						action(Bureaucrat const &executor)const;
};

#endif
