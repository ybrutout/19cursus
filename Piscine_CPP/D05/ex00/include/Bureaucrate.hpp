/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:42:51 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 14:19:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define	BUREAUCRATE_HPP

# include <iostream>

class Bureaucrate
{
	public:
		Bureaucrate();
		Bureaucrate(int grade, std::string name);
		Bureaucrate(Bureaucrate const & rhs);
		~Bureaucrate();

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

		Bureaucrate		&	operator=(Bureaucrate const & rhs);

		std::string			getName()const;
		int					getGrade()const;

		void				incrementingGrade();
		void				decrementingGrade();

	private:
		std::string			_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrate const & rhs);

#endif
