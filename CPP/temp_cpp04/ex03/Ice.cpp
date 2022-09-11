/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:33:30 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 15:59:25 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

//---------------constructors/destructor-------------------------//
Ice::Ice(void) {
	
	std::cout << "Ice default constructor called" << std::endl;
	this->setType("ice");
}

Ice::Ice(Ice const &src) {
	
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void) {
	
	std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const &rhs) {

	this->setType(rhs.getType());
	return (*this);
}

//--------------functionals-----------------//

Ice *Ice::clone() const {

	return (new Ice());
}

void	Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
