/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:03 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 07:51:32 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
WrongAnimal::WrongAnimal(void) : _type("<some animal name>") {
	
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs) {

	this->_type = rhs._type;
	return (*this);
}

//-------------------functionals-------------------------//

std::string WrongAnimal::getType(void) const {
	
	return (this->_type);
}

void WrongAnimal::makeSound(void) const {
	
	std::cout << "I-aaaaah" << std::endl;
}
