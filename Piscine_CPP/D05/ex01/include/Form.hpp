/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:18:37 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 15:41:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

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
		const int				getSigne()const;
		const int				getExecute()const;

		void					beSigned(Bureaucrat const & bureaucrat);
		void					signForm(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "grade is too high. Max grade is 1.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "grade is too Low. Min grade is 150.";
				}
		};

	private:
		const std::string		_name;
		bool					_status;
		const int				_signe;
		const int				_execute;
};

std::ostream	&	operator<<(std::ostream & o, Form const & rhs);



#endif
