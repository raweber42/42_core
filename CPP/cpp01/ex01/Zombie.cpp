/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:52:08 by raweber           #+#    #+#             */
/*   Updated: 2022/09/04 18:16:07 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	
	std::cout << "You killed the Zombie *" << this->name << "* with your shotgun!" << std::endl;
}

void Zombie::announce(void) {
	
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::give_name(std::string name) {
	
	this->name = name;
}
