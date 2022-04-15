/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:18:37 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 11:53:51 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(AForm const & rhs);
		AForm(std::string name, std::string target, int sign, int execute);
		virtual ~AForm();

		AForm		&			operator=(AForm const & rhs);

		const std::string		getName()const;
		bool					getStatus()const;
		int						getSigne()const;
		int						getExecute()const;
		const std::string		getTarget()const;

		void					beSigned(Bureaucrat const & bureaucrat);
		void					execute(Bureaucrat const & executor);
		virtual void			action() = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "'s grade is too high for this Aform.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "'s grade is too low for this Aform.";
				}
		};

		class NotSignException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The form isn't sign.";
				}
		};

	private:
		const std::string		_name;
		bool					_status;
		int const				_signe;
		int const				_execute;
		const std::string		_target;
};

std::ostream	&	operator<<(std::ostream & o, AForm const & rhs);

#endif
