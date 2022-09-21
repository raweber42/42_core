/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:18 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 15:22:45 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
WrongCat::WrongCat(void) {
	
	this->setType();
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal() {
	
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const &rhs) {

	this->_type = rhs._type;
	return (*this);
}

//-------------------functionals-------------------------//
 
void WrongCat::setType(void) {

	this->_type = "WrongCat";
}

void WrongCat::makeSound(void) const {
	
	std::cout << "MEOWWWWW" << std::endl;
}
