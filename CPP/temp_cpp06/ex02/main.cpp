/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:30:26 by raweber           #+#    #+#             */
/*   Updated: 2022/09/15 16:42:15 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main(void) {

	Base *newGen;
	
	newGen = generate();
	std::cout << "\nTRY IDENTIFYING BY POINTER" << std::endl;
	identify(newGen);
	
	std::cout << "\nTRY IDENTIFYING BY REFERENCE" << std::endl;
	identify(&(*newGen));
	std::cout << std::endl;
	return (0);
}
