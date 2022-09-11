/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:06:52 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 11:07:34 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_name) : weapon(weapon_name) {
	
	this->_name = name;
} 

HumanA::~HumanA(void) {
	
}

void HumanA::attack(void) {
	
	std::cout << this->_name << " attacks with their " << this->weapon.getType() << std::endl;
}
