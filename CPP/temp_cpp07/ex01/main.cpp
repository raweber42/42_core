/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:33:01 by raweber           #+#    #+#             */
/*   Updated: 2022/09/16 14:49:25 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void) {

	std::string arr[3] = {"This", "is", "Sparta"};

	std::cout << "\n### TRY PRINTING ###" << std::endl;
	iter(arr, 3, &printOut);
	std::cout << "\n### TRY TO MAKE BORING ###" << std::endl;	
	iter(arr, 3, &makeBoring);
	for (int i = 0; i < 3; i++)
		std::cout << (arr[i]) << std::endl;;
	std::cout << std::endl;
}