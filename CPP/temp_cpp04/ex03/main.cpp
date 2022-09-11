/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:25:56 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 09:21:25 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"


int main()
{
	{
		std::cout << "\x1B[34m" << "\n##### TEST FROM SUBJECT #####\n" << "\x1B[0m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\x1B[34m" << "\n##### MY TEST #####\n" << "\x1B[0m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << "\n#LEARN 5 Materias (one too much)" << std::endl;
		for (int i = 0; i < 5; i++)
			src->learnMateria(new Ice());
		std::cout << "\n#CREATE new Character" << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << "\n#EQUIP 5 Materias (one too much)" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		delete tmp;
		std::cout << "\n#CREATE new Character" << std::endl;
		ICharacter* bob = new Character("bob");
		std::cout << "\n#USE 5 Materias (one too much)" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		std::cout << "\n#Starting destruction..." << std::endl;
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}