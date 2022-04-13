/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:42:51 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 15:22:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(Bureaucrat const & rhs);
		~Bureaucrat();

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

		Bureaucrat		&	operator=(Bureaucrat const & rhs);

		std::string			getName()const;
		int					getGrade()const;

		void				incrementingGrade();
		void				decrementingGrade();

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
