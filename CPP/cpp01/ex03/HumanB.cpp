/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:07:53 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 14:50:29 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	
	this->_name = name;
}

HumanB::~HumanB(void) {
	
}

void	HumanB::setWeapon(Weapon &weapon_name) {

	this->weapon = &weapon_name;
}

void HumanB::attack(void) {
	
	std::cout << this->_name << " attacks with their " << this->weapon->getType() << std::endl;
}
