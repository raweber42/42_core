/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:50:29 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 15:56:05 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);
		MateriaSource & operator=(MateriaSource const &rhs);
		

		AMateria		*getMateriaSource(int i) const;
		void 			learnMateria(AMateria*);
		AMateria 		*createMateria(std::string const & type);
	
	private:
		AMateria *materiaList[4];
};

#endif