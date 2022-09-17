/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:13 by raweber           #+#    #+#             */
/*   Updated: 2022/09/17 08:15:10 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {

	std::cout << "# INITIALIZE EMPTY ARRAY" << std::endl;
	Array<int> empty_arr;
	std::cout << "Size of array is: " << empty_arr.size() << std::endl;
	std::cout << std::endl;

	std::cout << "# INITIALIZE *INT* ARRAY WITH ARGUMENT '5'" << std::endl;
	Array<int> filled_arr(5);
	std::cout << "Size of array is: " << filled_arr.size() << std::endl;
	std::cout << "### PRINT INT_ARR" << std::endl;
	for (int i = 0; i < filled_arr.size(); i++)
		std::cout << "Element Nr. " << i << " is: \"" << filled_arr[i] << "\"" << std::endl;
	std::cout << "### ASSIGN NEW VALUE TO INT_ARR[0]" << std::endl;
	filled_arr[0] = 42;
	std::cout << "### PRINT NEWLY ASSIGNED INT_ARR" << std::endl;
	for (int i = 0; i < filled_arr.size(); i++)
		std::cout << "Element Nr. " << i << " is: \"" << filled_arr[i] << "\"" << std::endl;
	std::cout << std::endl;

	std::cout << "# INITIALIZE *STRING* ARRAY WITH ARGUMENT '10'" << std::endl;
	Array<std::string> string_arr(5);
	std::cout << "Size of array is: " << string_arr.size() << std::endl;
	std::cout << "### PRINT STRING_ARR" << std::endl;
	for (int i = 0; i < string_arr.size(); i++)
		std::cout << "Element Nr. " << i << " is: \"" << string_arr[i] << "\"" << std::endl;
	std::cout << "### ASSIGN NEW VALUES TO STRING_ARR" << std::endl;
	string_arr[0] = "I <3 42";
	string_arr[1] = "Me too";
	string_arr[2] = "Who cares?";
	string_arr[3] = "Hello World";
	string_arr[4] = "Goodbye World";
	std::cout << "### PRINT NEWLY ASSIGNED STRING_ARR" << std::endl;
	for (int i = 0; i < string_arr.size(); i++)
		std::cout << "Element Nr. " << i << " is: \"" << string_arr[i] << "\"" << std::endl;
	
	std::cout << "### TRY ASSIGNING NEW VALUE TO STRING_ARR[50]" << std::endl;
	try {
		string_arr[50] = "I AM OUT OF BOUND, BUDDY!"; // WHY DOES THIS CRASH THE REST?
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "### TRY PRINTING VALUE STRING_ARR[50]" << std::endl;
	try {
		std::cout << string_arr[50] << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "### COPY FILLED_ARRAY IN EMPTY_ARRAY" << std::endl;
	empty_arr = filled_arr;
	std::cout << "First element is: " << empty_arr[0] << std::endl;

}