/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:52:38 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 10:06:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl 		harl;
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments. Try './harl_filter <arg>'" << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	
	harl.complain(input);
	return (0);
}