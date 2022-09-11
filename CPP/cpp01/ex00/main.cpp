/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:54:58 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 11:00:01 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "\n---Classic initalization---" << std::endl;
	Zombie zombie("Biter");
	zombie.announce();
	std::cout << "\n---Init with newZombie function (announces itself)---" << std::endl;
	Zombie *second = zombie.newZombie("Creeper");
	second->announce();
	delete second;
	std::cout << "\n---Init with randomChump function---" << std::endl;
	zombie.randomChump("Lame-brain");
	std::cout << "\n---End of main---" << std::endl;
}
