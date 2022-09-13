/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:59:52 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 19:01:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif