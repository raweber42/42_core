/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:38:33 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 11:01:17 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

ClapTrap::ClapTrap(void) : _name("Claptrap default robot"), _hit_points(10), _energy_points(10), _attack_damage(0) {

	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	
	std::cout << "ClapTrap constructor called with name: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hit_points(src._hit_points), _energy_points(src._energy_points), _attack_damage(src._attack_damage){
	
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	
	std::cout << "ClapTrap destructor called with name: " << _name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs) {
	
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hit_points = rhs.get_hit_points();
	this->_name = rhs.get_name();
	return (*this);
}

//--------------FUNCTIONALS---------------------------//

void ClapTrap::attack(const std::string& target) {

	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot attack anymore." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->_name << " does not have any energy points left, falls to the ground and cannot attack anymore." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;	
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead but the attacker doesnt stop stabbing..." << std::endl;
	else if (this->_hit_points - (int)amount > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hit_points -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " took a last serious hit and dies!" << std::endl;
		this->_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot repair himself anymore." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->_name << " does not have any energy points left to repair himself." << std::endl;
	else
	{
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repairs himself by drinking a magic potion restoring his hit points by " << amount << " up to " << this->_hit_points << std::endl;
		this->_energy_points--;	
	}
}

//------------GETTERS-----------------------------//

std::string	ClapTrap::get_name(void) const {

	return (this->_name);
}

int	ClapTrap::get_hit_points(void) const {
	
	return (this->_hit_points);
}

int	ClapTrap::get_energy_points(void) const {

	return (this->_energy_points);
}

int	ClapTrap::get_attack_damage(void) const {

	return (this->_attack_damage);	
}
