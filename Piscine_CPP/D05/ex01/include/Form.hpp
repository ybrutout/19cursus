/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:18:37 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 13:01:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(Form const & rhs);
		Form(std::string name, int sign, int execute);
		~Form();

		Form		&			operator=(Form const & rhs);

		const std::string		getName()const;
		bool					getStatus()const;
		int						getSigne()const;
		int						getExecute()const;

		void					beSigned(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low.";
				}
		};

	private:
		const std::string		_name;
		bool					_status;
		int const				_signe;
		int const				_execute;
};

std::ostream	&	operator<<(std::ostream & o, Form const & rhs);

#endif
