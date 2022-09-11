/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:04:31 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 09:11:52 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <algorithm>

//---------------constructors/destructor-------------------------//

Character::Character(void) {
	
	this->setName("RANDOM_USER");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) {
	
	this->setName(name);
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character constructor called with name: " << this->getName() << std::endl;
}

Character::Character(Character const &src) {
	
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void) {
	
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character & Character::operator=(Character const &rhs) {

	this->setName(rhs.getName());
	return (*this);
}

//---------------FUNCTIONALS-------------------------//

std::string const & Character::getName() const {

	return(this->name);	
}

void Character::equip(AMateria* m) {

	int i = 0;
	while (i < 4 && this->inventory[i])
		i++;
	if (i < 4)
		this->inventory[i] = m;
	else
		std::cout << "Character cannot equip anymore, inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
	
	if (this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {

	if (idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "Index " << idx << " is too high! The inventory has only four slots!" << std::endl;
}

void Character::setName(std::string new_name) {

	this->name = new_name;
}
