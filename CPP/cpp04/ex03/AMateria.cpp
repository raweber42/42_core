/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:36:52 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 09:37:31 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include "AMateria.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//

AMateria::AMateria(void) {
	
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & new_type) {

	this->setType(new_type);
	std::cout << "AMateria constructor called with name: " << this->type << std::endl;
}

AMateria::AMateria(AMateria const &src) {
	
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void) {
	
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const &rhs) {

	std::cout << "AMateria assignment operator called" << std::endl;
	this->type = rhs.type; // NOT NEEDED? COMMENT
	return (*this);
}

//--------------functionals-----------------//

std::string const & AMateria::getType() const {
	
	return(this->type);
}

void AMateria::use(ICharacter& target) {
	
	std::cout << "* default attack (from AMateria) on " << target.getName() << " *" << std::endl;

}

void AMateria::setType(std::string new_type) {

	this->type = new_type;
}
