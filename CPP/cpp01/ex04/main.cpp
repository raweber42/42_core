/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:02:43 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 11:16:31 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void replace_string(std::string line, std::string s1, std::string s2, std::ofstream	&ofs)
{
	std::string	replaced;
	size_t		start_sub;
	size_t		end_sub;
	size_t		copy_len;

	start_sub = line.find(s1);
	copy_len = start_sub;
	end_sub = 0;
	while (start_sub != std::string::npos)
	{
		replaced += line.substr(end_sub, copy_len);
		end_sub = start_sub + s1.length();
		replaced += s2;
		start_sub = line.find(s1, end_sub);
		copy_len = start_sub - end_sub;
	}
	replaced += line.substr(end_sub, line.length());
	
	ofs << replaced;
	if (line.find('\n'))
		ofs << '\n';
}


int main(int argc, char **argv)
{
	if (argc != 4) 
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}

	std::ifstream	ifs(argv[1]);
	std::string		arg1(argv[1]);
	std::ofstream	ofs(arg1 + ".replace");
	std::string		line;
	
	if (!ifs || !ofs) {
		std::cout << "Could not open files!" << std::endl;
		return (1);
	}
	if (ifs.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "File is empty!" << std::endl;
		return (1);
	}
	else if (ifs.good() && ofs.good())
	{
		while (getline(ifs, line))
		{	
			if (line.find(argv[2]) != std::string::npos)
				replace_string(line, argv[2], argv[3], ofs);
			else {
				ofs << line;
				if (line.find('\n'))
					ofs << '\n';
			}
		}
	}
	ifs.close();
	ofs.close();
}
