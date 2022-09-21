/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:03 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:06:54 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
Animal::Animal(void) : _type("<some animal name>") {
	
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) {
	
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void) {
	
	std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const &rhs) {

	this->_type = rhs._type;
	return (*this);
}

//-------------------functionals-------------------------//

std::string Animal::getType(void) const {
	
	return (this->_type);
}

void Animal::makeSound(void) const {
	
	std::cout << "<some animal sound>" << std::endl;
}
