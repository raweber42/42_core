/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:23:08 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 07:01:55 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;
	
	std::cout << "\n---Print memory addresses---\n";
	std::cout << "Memory Address of String Variable: " << &string << std::endl;
	std::cout << "Memory Address of stringPTR: " << &(stringPTR) << std::endl;
	std::cout << "Memory Address of stringREF: " << &(stringREF) << std::endl;

	std::cout << "\n---Print values of variables---\n";
	std::cout << "Value of String Variable: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	return (0);
}