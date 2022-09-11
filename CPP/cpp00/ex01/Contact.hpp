/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:14:09 by raweber           #+#    #+#             */
/*   Updated: 2022/09/03 11:18:57 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	
	public:

		Contact(void);
		~Contact(void);
		int			get_index(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nick_name(void);
		std::string	get_phone_number(void);
		std::string	get_secret(void);
		void		set_index(int value);
		void		set_first_name(std::string value);
		void		set_last_name(std::string value);
		void		set_nick_name(std::string value);
		void		set_phone_number(std::string value);
		void		set_secret(std::string value);

	private:

		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif