/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:18 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 09:15:42 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
Cat::Cat(void) {
	
	this->setType();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal() {
	
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const &rhs) {

	this->_type = rhs._type;
	return (*this);
}

//-------------------functionals-------------------------//
 
void Cat::setType(void) {

	this->_type = "Cat";
}

void Cat::makeSound(void) const {
	
	std::cout << "MEOWWWWW" << std::endl;
}
