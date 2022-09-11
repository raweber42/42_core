/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:49 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 11:41:43 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

ScavTrap::ScavTrap(void) {

	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {

	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	
	this->_name = src.get_name();
	this->_hit_points = src.get_hit_points();
	this->_energy_points = src.get_energy_points();
	this->_attack_damage = src.get_attack_damage();
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap destructor called with name: " << _name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs) {
	
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hit_points = rhs.get_hit_points();
	this->_name = rhs.get_name();
	return (*this);
}

//--------------FUNCTIONALS------------------//

void ScavTrap::set_hit_points(void) {
	
	this->_hit_points = 100;
}

void ScavTrap::set_energy_points(void) {

	this->_energy_points = 50;
}

void ScavTrap::set_attack_damage(void) {

	this->_attack_damage = 20;
}

void ScavTrap::attack(const std::string& target) {

	if (this->_hit_points == 0)
		std::cout << "ScavTrap " << this->_name << " is already dead and cannot attack anymore." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "ScavTrap " << this->_name << " does not have any energy points left, falls to the ground and cannot attack anymore." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;	
	}
}

void ScavTrap::guardGate(void) {

	std::cout << "ScavTrap is now in gatekeeper mode" << std::endl;
}
