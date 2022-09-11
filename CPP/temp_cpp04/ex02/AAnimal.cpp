/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:03 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 09:54:01 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
AAnimal::AAnimal(void) : _type("<some animal name>") {
	
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void) {
	
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const &rhs) {

	this->_type = rhs._type;
	return (*this);
}

//-------------------functionals-------------------------//

std::string AAnimal::getType(void) const {
	
	return (this->_type);
}

void AAnimal::makeSound(void) const {
	
	std::cout << "<some animal sound>" << std::endl;
}
