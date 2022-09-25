/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:22 by raweber           #+#    #+#             */
/*   Updated: 2022/09/25 11:39:12 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
Dog::Dog(void) {
	
	std::cout << "Dog default constructor called" << std::endl;
	this->setType();
	this->brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal() {
	
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const &rhs) {

	this->_type = rhs._type;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, rhs.brain->getIdea(i));
	return (*this);
}

//--------------functionals-----------------//

void Dog::setType(void) {

	this->_type = "Dog";
}

void Dog::makeSound(void) const {
	
	std::cout << "WRAFFFFFFF" << std::endl;
}

std::string	Dog::getIdea(int i) const {

	return(this->brain->getIdea(i));
}

void Dog::setIdea(int i, std::string new_idea) {

	this->brain->setIdea(i, new_idea);
}
