/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:14:04 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 11:52:36 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
	
	public:
	
		PhoneBook(void);
		~PhoneBook(void);
		
		Contact		get_contact(int index) const;
		void		set_contact(std::string *new_contact);
		void		search_contact(void) const;
		int			add_contact(void);

	private:

		void		read_loop(std::string &parameter) const;
		void		print_spaces(std::string str) const;
		void		print_column(Contact current) const;
		
		
		Contact contacts[8];

};

#endif