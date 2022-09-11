/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 08:04:20 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 10:44:52 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	
}

Harl::~Harl(void) {
	
}

void Harl::complain(std::string &level) {
	
	int i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			switch (i)
			{
				case 0:
					while (i < 4)
						(this->*fptr[i++])();
				case 1:
					while (i < 4)
						(this->*fptr[i++])();
				case 2:
					while (i < 4)
						(this->*fptr[i++])();
				case 3:
					while (i < 4)
						(this->*fptr[i++])();
			}
			return ;
		}
	}
	std::cout << "\n## INVALID INPUT ##" << std::endl;
	std::cout << "No argument valid given, Harl stays quiet.\n" << std::endl;
}

void Harl::debug(void) {
	
	std::cout << "\n## DEBUG ##" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) {

	std::cout << "\n## INFO ##" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {

	std::cout << "\n## WARNING ##" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {

	std::cout << "\n## ERROR ##" << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
