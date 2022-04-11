/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:32:44 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 13:39:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & rhs);
		~MateriaSource();

		MateriaSource	&	operator=(MateriaSource const & rhs);

		void learnMateria(AMateria* rhs);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria	*_tab[4];
};

#endif
