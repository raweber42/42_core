/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:16:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 12:07:51 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>

int	main(void)
{
	PhoneBook		my_phonebook;
	std::string		user_command;

	std::cout << "\n### WELCOME TO YOUR AWESOME PHONEBOOK ###\n" << std::endl;
	std::cout << "## Simply type 'ADD', 'SEARCH' or 'EXIT' in order to use me! ##\n> ";
	
	while (getline(std::cin, user_command))
	{
		// std::getline(std::cin, user_command);
		if (user_command == "ADD")
		{
			if (my_phonebook.add_contact())
				break ;
		}
		else if (user_command == "SEARCH")
		{
			my_phonebook.search_contact();
		}
		else if (user_command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "\n# I am sorry, but you entered an invalid command. Try 'ADD', 'SEARCH' or 'EXIT'!" << std::endl;	
		}
		std::cout << "\n# What do you want to do next? (ADD, SEARCH, EXIT)\n> "; // handle, that this isnt printed anymore after ctrl+d
	}
	std::cout << "\n\n### Thanks for using your awesome phonebook! ###\n\n";

	return (0);
}
