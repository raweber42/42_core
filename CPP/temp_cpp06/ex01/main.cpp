/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:41:15 by raweber           #+#    #+#             */
/*   Updated: 2022/09/15 15:18:00 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "structure.hpp"

Data* deserialize(uintptr_t raw) {
	
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data* ptr) {
	
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main(void) {

	Data		example;
	example.attr1 = "THIS IS MAMBO NR...";
	example.attr2 = 5;
	
	uintptr_t	serialized;
	Data*		deserialized;
	
	serialized = serialize(&example);
	deserialized = deserialize(serialized);
	
	std::cout << "\nPRINT ADDRESSES" << std::endl;
	std::cout << "&example = " << &example << std::endl;
	std::cout << "serialized = " << serialized << std::endl;
	std::cout << "deserialized = " << deserialized << std::endl;

	std::cout << "\nPRINT ADDRESSES" << std::endl;
	std::cout << "Print first attribute of struct: " << (*deserialized).attr1 << std::endl;
	std::cout << "Print second attribute of struct: " << (*deserialized).attr2 << std::endl; 

	std::cout << "Try the first attribute with reinterpret cast from 'serialized': " << (reinterpret_cast<Data *>(serialized))->attr1 << std::endl;
	std::cout << "Try the second attribute with reinterpret cast from 'serialized': " << (reinterpret_cast<Data *>(serialized))->attr2 << std::endl;
	std::cout << std::endl;
}