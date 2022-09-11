/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:14:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 14:14:28 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	
	// std::cout << "PhoneBook constructor called" << std::endl;
	// return ;
}

PhoneBook::~PhoneBook(void) {
	
	// std::cout << "PhoneBook destructor called" << std::endl;
	// return ;
}

void	PhoneBook::set_contact(std::string *new_contact) {
	
	int	i = 0;
	while (i < 8)
	{
		if (!this->contacts[i].get_first_name().empty())
			i++;
		else
			break;
	}
	if (i == 8)
		i = 0;
	this->contacts[i].set_index(i);
	this->contacts[i].set_first_name(new_contact[0]);
	this->contacts[i].set_last_name(new_contact[1]);
	this->contacts[i].set_nick_name(new_contact[2]);
	this->contacts[i].set_phone_number(new_contact[3]);
	this->contacts[i].set_secret(new_contact[4]);
}

Contact	PhoneBook::get_contact(int index) const {

	return (this->contacts[index]);
}


void	PhoneBook::read_loop(std::string &parameter) const {

	std::cout << "> ";
	while (std::getline(std::cin, parameter))
	{
		std::cout << "> ";
		if (!parameter.empty())
			return ;
	}
}

int	PhoneBook::add_contact(void) {
	
	std::string		new_contact[5];

	std::cout << "# Please enter the *first name* of the new contact:\n";
	read_loop(new_contact[0]);
	if (new_contact[0].empty())
		return (1);
	std::cout << "# Please enter the *last name* of the new contact:\n";
	read_loop(new_contact[1]);
	if (new_contact[1].empty())
		return (1);
	std::cout << "# Please enter the *nickname* of the new contact:\n";
	read_loop(new_contact[2]);
	if (new_contact[2].empty())
		return (1);
	std::cout << "# Please enter the *phone number* of the new contact:\n";
	read_loop(new_contact[3]);
	if (new_contact[3].empty())
		return (1);
	std::cout << "# Please enter the *darkest secret* of the new contact:\n";
	read_loop(new_contact[4]);
	if (new_contact[4].empty())
		return (1);
	PhoneBook::set_contact(new_contact);
	std::cout << "\n# SUCCESSFULLY SET NEW CONTACT #" << std::endl;
	return (0);
}

void	PhoneBook::print_spaces(std::string str) const {
	
	size_t	length;

	length = str.size();
	if (length > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setw(10) << str;
}

void	PhoneBook::print_column(Contact current) const {
	
	if (!current.get_first_name().empty())
	{
		std::cout << "|" << std::setw(9) << current.get_index();
		std::cout << "|";
		print_spaces(current.get_first_name());
		std::cout << "|";
		print_spaces(current.get_last_name());
		std::cout << "|";
		print_spaces(current.get_nick_name());
		std::cout << "|\n";
	}
}

void	PhoneBook::search_contact(void) const {

	Contact		cur_contact;
	std::string first_name;
	std::string	temp;
	int			search_index;
	
	cur_contact = this->get_contact(0);
	if (cur_contact.get_first_name().empty())
	{
		std::cout << "# Bro, you don't have any friends! #\n";
		return ;
	}
	std::cout << "\n#-----------------CONTACTS-----------------#\n";
	for (int i = 0; i < 8; i++)
	{
		print_column(cur_contact);
		if (i < 7)
			cur_contact = this->get_contact(i + 1);
	}
	std::cout << "#------------------------------------------#\n";
	std::cout << "\n# Now, please enter the number of the entry you want to see:\n> ";
	std::getline(std::cin, temp);
	search_index = (temp[0] - 48);
	if (temp[1])
		search_index = -1;
	if (search_index < 0 || search_index > 7 || this->get_contact(search_index).get_first_name().empty())
	{
		std::cout << "The index you entered is invalid!\n";
		return ;
	}
	std::cout << "\n#----------CONTACT INFORMATION----------#\n";
	std::cout << "$ First name:\t\t" << this->get_contact(search_index).get_first_name() << std::endl;
	std::cout << "$ Last name:\t\t" << this->get_contact(search_index).get_last_name() << std::endl;
	std::cout << "$ Nickname:\t\t" << this->get_contact(search_index).get_nick_name() << std::endl;
	std::cout << "$ Phone number:\t\t" << this->get_contact(search_index).get_phone_number() << std::endl;
	std::cout << "$ Darkest secret:\t" << this->get_contact(search_index).get_secret() << std::endl;
	std::cout << "\n#---------------------------------------#\n";
}
