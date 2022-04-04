/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:47:13 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 15:23:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const & brain);
		~Brain();

		Brain	&		operator=(Brain const & brain);

		std::string		getIdea(int i)const;
		void			setIdea(std::string idea);
	private:
		std::string		*_idea[100];
};

#endif
