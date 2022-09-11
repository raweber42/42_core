/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:08:27 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 11:09:21 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
	Weapon club = Weapon("baguette");
	HumanA guillaume("Guillaume", club);
	guillaume.attack();
	club.setType("grilled snails");
	guillaume.attack();
	}
	{
	Weapon club = Weapon("welsh cookies");
	HumanB bethan("Bethan");
	bethan.setWeapon(club);
	bethan.attack();
	club.setType("more welsh cookies");
	bethan.attack();
	}
	{
	Weapon club = Weapon("lasersword");
	HumanB ralf("Ralf");
	ralf.setWeapon(club);
	ralf.attack();
	club.setType("");
	ralf.attack();
	}
	return (0);
}
