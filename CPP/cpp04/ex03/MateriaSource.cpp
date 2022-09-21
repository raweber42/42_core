/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:50:32 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 08:55:44 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//

MateriaSource::MateriaSource(void) {
	
	for (int i = 0; i < 4; i++)
		this->materiaList[i] = 0;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	
	for (int i = 0; i < 4; i++)
		this->materiaList[i] = 0;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void) {
	
	for (int i = 0; i < 4; i++)
		delete this->materiaList[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs) {

	for (int i = 0; i < 4; i++)
		this->materiaList[i] = rhs.getMateriaSource(i);
	return (*this);
}

//---------------FUNCTIONALS-------------------------//

AMateria	*MateriaSource::getMateriaSource(int i) const {
	
	return (this->materiaList[i]);
}


void MateriaSource::learnMateria(AMateria* new_materia) {

	int i;
	for (i = 0; i < 4; i++)
	{
		if (getMateriaSource(i) == 0) {
			this->materiaList[i] = new_materia;
			return ;
		}
	}
	std::cout << "Cannot learn more materias, MateriaSource is full!" << std::endl;
	delete new_materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	
	int i = 0;
	while (i < 4 && this->materiaList[i] && this->materiaList[i]->getType().compare(type))
		i++;
	if (i < 4 && this->materiaList[i])
		return (this->materiaList[i]->clone());
	else
		return (0);
}
