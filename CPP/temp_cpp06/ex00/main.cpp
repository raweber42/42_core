/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:12:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/15 11:31:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

int handlePseudo(std::string input)
{
	int	i;
	std::string pseudoArr[8] = {"inff", "+inff", "-inff", "nanf", "inf", "+inf", "-inf", "nan"};
	
	for (i = 0; i < 8; i++)
		if (!input.compare(pseudoArr[i]))
			break;
	if (i < 8)
	{
		//----------------PRINT CHAR------------------------
		std::cout << "char: Non displayable" << std::endl;
		//------------------------PRINT INT//----------------
		std::cout << "int: Non displayable" << std::endl;
		//------------------------PRINT FLOAT------------------------
		std::cout << "float: " << ((i < 4)?(pseudoArr[i]):("Undefined behavior")) << std::endl;
		//------------------------PRINT DOUBLE------------------------
		std::cout << "double: " << ((i >= 4)?(pseudoArr[i]):("Undefined behavior")) << std::endl;
		return (1);
	}
	return (0);
}

void handleChar(char c)
{
	//----------------PRINT CHAR------------------------
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//------------------------PRINT INT//----------------
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	//------------------------PRINT FLOAT------------------------
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	//------------------------PRINT DOUBLE------------------------
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

int main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments!" << std::endl;
		return (1);
	}
	
	std::string char_string(argv[1]);
	double		double_value = 0.0;
	float		float_value = 0.0f;
	char *		endptr_d;
	char *		endptr_f;

	// std::cout << static_cast<int>(argv[1][0]) << std::endl;
	
	// char, int, float or double
	if (handlePseudo(char_string))
		return (0);
	double_value = std::strtod(argv[1], &endptr_d);
	float_value = std::strtof(argv[1], &endptr_f);
	if (isdigit(char_string[0]) || char_string.length() > 1)
	{
		if (*endptr_d || *endptr_f)
		{
			std::cout << "Error: Invalid input. Only one of: char, int, float or double!" << std::endl;
			return (1);
		}
	}
	else
	{
		handleChar(argv[1][0]);
		return (0);
	}
	//----------------PRINT CHAR------------------------
	if (isprint(floorf(float_value)))
		std::cout << "char: \'" << static_cast<char>(double_value) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//------------------------PRINT INT//----------------
	if (double_value > INT32_MAX || double_value < INT32_MIN)
		std::cout << "int: Non displayable (overflow)" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(double_value) << std::endl;
	//------------------------PRINT FLOAT------------------------
	if (double_value > std::numeric_limits<float>::max() || double_value < std::numeric_limits<float>::min())
		std::cout << "float: Non displayable (overflow)" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(double_value) << (floorf(double_value)==double_value?".0f":"f")<< std::endl;
	//------------------------PRINT DOUBLE------------------------
	if (double_value == INFINITY || double_value == -INFINITY)
		std::cout << "double: " << double_value << std::endl;
	else
		std::cout << "double: " << double_value << (floor(double_value)==double_value?".0":"") << std::endl;
}

// NOW -> INF etc