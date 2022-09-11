/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:29:36 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 10:52:15 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Anakin("ANAKIN");
	ClapTrap Rae("RAE");

	std::cout << std::endl;
	std::cout << "\x1B[31m" << "#### STATUS ####" << std::endl;
	std::cout << Anakin.get_name() << " starts with " << Anakin.get_attack_damage() << " damage points, " << Anakin.get_energy_points() << " energy points and " << Anakin.get_hit_points() << " hit points." << std::endl;
	std::cout << Rae.get_name() << " starts with " << Rae.get_attack_damage() << " damage points, " << Rae.get_energy_points() << " energy points and " << Rae.get_hit_points() << " hit points." << "\033[0m" << std::endl;
	std::cout << std::endl;
	
	Anakin.attack("RAE");
	Rae.takeDamage(12);
	std::cout << std::endl;
	Rae.attack("ANAKIN");
	Anakin.takeDamage(3);
	
	std::cout << std::endl;
	std::cout << "\x1B[31m" << "#### STATUS ####" << std::endl;
	std::cout << Anakin.get_name() << " currently has " << Anakin.get_attack_damage() << " damage points, " << Anakin.get_energy_points() << " energy points and " << Anakin.get_hit_points() << " hit points." << std::endl;
	std::cout << Rae.get_name() << " currently has " << Rae.get_attack_damage() << " damage points, " << Rae.get_energy_points() << " energy points and " << Rae.get_hit_points() << " hit points." << "\033[0m" << std::endl;
	std::cout << std::endl;
	
	Anakin.beRepaired(2);
	Rae.beRepaired(0);
	
	std::cout << std::endl;
	std::cout << "\x1B[31m" << "#### STATUS ####" << std::endl;
	std::cout << Anakin.get_name() << " currently has " << Anakin.get_attack_damage() << " damage points, " << Anakin.get_energy_points() << " energy points and " << Anakin.get_hit_points() << " hit points." << std::endl;
	std::cout << Rae.get_name() << " currently has " << Rae.get_attack_damage() << " damage points, " << Rae.get_energy_points() << " energy points and " << Rae.get_hit_points() << " hit points." << "\033[0m" << std::endl;
	std::cout << std::endl;
	
	Anakin.attack("RAE");
	Rae.takeDamage(5);
	std::cout << std::endl;
	Rae.attack("ANAKIN");
	Anakin.takeDamage(3);

	std::cout << std::endl;
	std::cout << "\x1B[31m" << "#### STATUS ####" << std::endl;
	std::cout << Anakin.get_name() << " currently has " << Anakin.get_attack_damage() << " damage points, " << Anakin.get_energy_points() << " energy points and " << Anakin.get_hit_points() << " hit points." << std::endl;
	std::cout << Rae.get_name() << " currently has " << Rae.get_attack_damage() << " damage points, " << Rae.get_energy_points() << " energy points and " << Rae.get_hit_points() << " hit points." << "\033[0m" << std::endl;
	std::cout << std::endl;
	
	// std::cout <<  << std::endl;
	
}