/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:34:05 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 07:50:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong_i = new WrongCat();
	
	std::cout << std::endl;
	std::cout << "### TYPES OF ANIMALS ###" << std::endl;
	std::cout << "Dog type is: " << j->getType() << " " << std::endl;
	std::cout << "Cat type is: " << i->getType() << " " << std::endl;
	std::cout << "Wrong Cat type is: "<< wrong_i->getType() << " " << std::endl;
	std::cout << "Animal type is: "<< meta->getType() << " " << std::endl;


	std::cout << std::endl;
	std::cout << "### ANIMALS MAKING SOUNDS ###" << std::endl;
	std::cout << "Dog: ";
	i->makeSound();
	std::cout << "Cat: ";
	j->makeSound();
	std::cout << "Wrong Cat: ";
	wrong_i->makeSound();
	std::cout << "Animal: ";
	meta->makeSound();
	std::cout << "Wrong Animal: ";
	wrong_meta->makeSound();
	std::cout << std::endl;

	delete wrong_i;
	delete i;
	delete j;
	delete wrong_meta;
	delete meta;
	
	return 0;
}

// SUBJECT EXAMPLE
// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	return 0;
// }

// MY EXAMPLE WITHOUT POINTERS
// int main(void)
// {
// 	Animal		animal;
// 	Cat			cat;
// 	Dog			dog;
// 	WrongAnimal	wrong_animal;
// 	WrongCat	wrong_cat;
	
// 	std::cout << std::endl;
// 	std::cout << "### TYPES OF ANIMALS ###" << std::endl;
// 	std::cout << "The type of the animal is: " << animal.getType() << std::endl; 
// 	std::cout << "The type of the cat is: " << cat.getType() << std::endl; 
// 	std::cout << "The type of the dog is: " << dog.getType() << std::endl;
// 	std::cout << "The type of the wrong_animal is: " << wrong_animal.getType() << std::endl;
// 	std::cout << "The type of the wrong_cat is: " << wrong_cat.getType() << std::endl; 
	
// 	std::cout << std::endl;
// 	std::cout << "### ANIMALS MAKING SOUNDS ###" << std::endl;
// 	std::cout << "Animal: ";
// 	animal.makeSound();
// 	std::cout << "Cat: ";
// 	cat.makeSound();
// 	std::cout << "Dog: ";
// 	dog.makeSound();
// 	std::cout << "Wrong Animal: ";
// 	wrong_animal.makeSound();
// 	std::cout << "Wrong Cat: ";
// 	wrong_cat.makeSound();
// 	std::cout << std::endl;

// }