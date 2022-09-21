/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:33:30 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 09:35:30 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
Cure::Cure(void) {
	
	std::cout << "Cure default constructor called" << std::endl;
	this->setType("cure");
}

Cure::Cure(Cure const &src) : AMateria() {
	
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure(void) {
	
	std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const &rhs) {

	this->setType(rhs.getType());
	return (*this);
}

//--------------functionals-----------------//

Cure *Cure::clone() const {

	return (new Cure());
}

void	Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
