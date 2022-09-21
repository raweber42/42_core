/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:49 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 09:11:06 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

DiamondTrap::DiamondTrap(void) {

	this->FragTrap::set_hit_points();
	this->ScavTrap::set_energy_points();
	this->FragTrap::set_attack_damage();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {

	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::set_hit_points();
	this->ScavTrap::set_energy_points();
	this->FragTrap::set_attack_damage();
	std::cout << "DiamondTrap constructor called with name: " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src.get_name()), ScavTrap(src.get_name()), FragTrap(src.get_name()) {
	
	this->_name = src.get_name();
	this->_hit_points = src.get_hit_points();
	this->_energy_points = src.get_energy_points();
	this->_attack_damage = src.get_attack_damage();
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {

	std::cout << "DiamondTrap destructor called with name: " << this->_name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &rhs) {
	
	this->_name = rhs.get_name();
	this->_hit_points = rhs.get_hit_points();
	this->_energy_points = rhs.get_energy_points();
	this->_attack_damage = rhs.get_attack_damage();
	return (*this);
}

//--------------FUNCTIONALS---------------------------//

void DiamondTrap::whoAmI(void) {
	
	std::cout << "My name is " << this->_name << " and my claptrap name is " << ClapTrap::_name << std::endl;
}
