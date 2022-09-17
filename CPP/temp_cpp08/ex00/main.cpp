/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:29:18 by raweber           #+#    #+#             */
/*   Updated: 2022/09/17 15:17:40 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template<typename T>
void printContainer(T container_elem) {

	std::cout << "Element Nr. " << "i" << " is " << container_elem << std::endl;
}

int main(void) {

	std::cout << "### TEST EASYFIND WITH VECTOR ###" << std::endl;
	std::vector<int>	myVector;
	int					j = 0;

	myVector.push_back(0);
	myVector.push_back(10);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(3);
	myVector.push_back(10);

	std::cout << "# PRINT VECTOR #" << std::endl;
	for (unsigned int i = 0; i < myVector.size(); i++)
		std::cout << "Element Nr. " << i << " is " << myVector[i] << std::endl;

	std::cout << "# TRY FINDING ELEMENT '3' IN VECTOR #" << std::endl;
	std::vector<int>::iterator it;
	try {
		it = easyfind(myVector, 10);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "# TRY FINDING ELEMENT '5' IN VECTOR #" << std::endl;
	try {
		it = easyfind(myVector, 5);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	

	std::cout << "# PROOF THAT IT FOUND THE FIRST OCCURENCE #" << std::endl;
	for (std::vector<int>::iterator i = myVector.begin(); i != it; i++)
		j++;
	std::cout << "The element found was at at index: " << j << std::endl;
	std::cout << std::endl;
		

	//---------------------------------------------------------------

	std::cout << "### TEST EASYFIND WITH DEQUE ###" << std::endl;
	std::deque<int> 			myDeque(4, 3);
	std::deque<int>::iterator	iter;
	
	std::cout << "# PRINT DEQUE #" << std::endl;
	for (unsigned int i = 0; i < myDeque.size(); i++)
		std::cout << "Element Nr. " << i << " is " << myDeque[i] << std::endl;

	std::cout << "# TRY FINDING ELEMENT '3' IN DEQUE #" << std::endl;
	try {
		iter = easyfind(myDeque, 3);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "# TRY FINDING ELEMENT '5' IN DEQUE #" << std::endl;
	try {
		iter = easyfind(myDeque, 5);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << std::endl;


//---------------------------------------------------------------

	std::cout << "### TEST EASYFIND WITH LIST ###" << std::endl;
	std::list<int> 				myList(4, 3);
	std::list<int>::iterator	iterator;
	
	j = 0;
	std::cout << "# PRINT LIST #" << std::endl;
	for (std::list<int>::iterator i = myList.begin(); i != myList.end(); i++)
		std::cout << "Element Nr. " << j++ << " is " << *myList.begin() << std::endl;

	std::cout << "# TRY FINDING ELEMENT '3' IN LIST #" << std::endl;
	try {
		iterator = easyfind(myList, 3);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "# TRY FINDING ELEMENT '5' IN LIST #" << std::endl;
	try {
		iterator = easyfind(myList, 5);
		std::cout << "Found element!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << std::endl;

	return (0);
}

// how to print the right index?
