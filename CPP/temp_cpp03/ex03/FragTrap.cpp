/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:49 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 11:35:00 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

FragTrap::FragTrap(void) {

	this->set_hit_points();
	this->set_energy_points();
	this->set_attack_damage();
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {

	this->_name = name;
	this->set_hit_points();
	this->set_energy_points();
	this->set_attack_damage();
	std::cout << "FragTrap constructor called with name: " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {
	
	this->_name = src.get_name();
	this->_hit_points = src.get_hit_points();
	this->_energy_points = src.get_energy_points();
	this->_attack_damage = src.get_attack_damage();
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {

	std::cout << "FragTrap destructor called with name: " << _name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs) {
	
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hit_points = rhs.get_hit_points();
	this->_name = rhs.get_name();
	return (*this);
}

//--------------FUNCTIONALS------------------//

void FragTrap::set_hit_points(void) {
	
	this->_hit_points = 100;
}

void FragTrap::set_energy_points(void) {

	this->_energy_points = 100;
}

void FragTrap::set_attack_damage(void) {

	this->_attack_damage = 30;
}

void FragTrap::highFivesGuys(void) {
	
	if (this->_hit_points == 0)
		std::cout << "FragTrap " << this->_name << " is already dead and cannot high five anymore." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "FragTrap " << this->_name << " does not have any energy points and cannot high five anymore." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " says: Give me high five, guys!" << std::endl;
}
