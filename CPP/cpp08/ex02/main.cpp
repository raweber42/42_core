/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:28:02 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 12:27:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(void) {

	std::cout << "### CREATE MUTANTSTACK WITH VALUES 1-5 ###" << std::endl;
	MutantStack<int> myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	MutantStack<int>::Iterator it_start = myStack.begin();
	MutantStack<int>::Iterator it_end = myStack.end();

	std::cout << "### PRINT MUTANTSTACK ###" << std::endl;
	while (it_start != it_end)
		std::cout << "Value is: " << *it_start++ << std::endl;

	std::cout << "\n# FOR COMPARISON NOW WITH LIST: #\n" << std::endl;

	std::cout << "### CREATE STD::LIST WITH VALUES 1-5 ###" << std::endl;
	std::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_back(5);

	std::cout << "### PRINT STD::LIST ###" << std::endl;
	for (std::list<int>::iterator i = myList.begin(); i != myList.end(); i++)
		std::cout << "Value is: " << *i << std::endl;
	std::cout << std::endl;
}

// FROM SUBJECT PAPER:
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::Iterator it = mstack.begin();
// 	MutantStack<int>::Iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
