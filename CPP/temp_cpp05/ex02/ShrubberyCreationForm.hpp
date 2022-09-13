/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:33:13 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 19:00:42 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;

};

#endif