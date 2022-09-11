/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:54:58 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 11:02:35 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "\n---Start of main---" << std::endl;
	int N = 20;
	std::cout << "\n---A Horde of Zombies appears!---" << std::endl;

	Zombie *zombielist = zombieHorde(N, "Lame-brain");
	for (int i = 0; i < N; i++)
		zombielist[i].announce();
	
	std::cout << "\n---You get out your shotgun and ...---" << std::endl;
	delete [] zombielist;
	std::cout << "\n---End of main---" << std::endl;
}
