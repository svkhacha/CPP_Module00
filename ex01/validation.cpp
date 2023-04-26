/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:22 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:31:28 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iostream>

void	print_input_place(int index)
{
	if (index == 0)
		std::cout<<CYAN "🔷 First Name: " RESET;
	else if (index == 1)
		std::cout<<CYAN "🔷 Last Name: " RESET;
	else if (index == 2)
		std::cout<<CYAN "🔷 Nickname: " RESET;
	else if (index == 3)
		std::cout<<CYAN "🔷 Phone Number: " RESET;
	else if (index == 4)
		std::cout<<CYAN "🔷 Darkest Secret: " RESET;
}

int	validate_input_data(std::string info, int index)
{
	if (index == 0 || index == 1)
	{
		for (unsigned int i = 0; i < info.length(); i++)
		{
			if (!isalpha(info[i]))
			{
				std::cout<<RED "❌ ERROR: You can use only alphabetic characters :(" RESET;
				std::cout<<std::endl;
				std::cout<<BLUE "Try again !" RESET<<std::endl;
				return -1;
			}
		}
	}
	else if (index == 3)
	{
		for (unsigned int i = 0; i < info.length(); i++)
		{
			if ((info[i] == '+' && i != 0) || (!isdigit(info[i]) && info[i] != '+'))
			{
				std::cout<<RED "❌ ERROR: You can use only numeric characters :(" RESET;
				std::cout<<std::endl;
				std::cout<<BLUE "Try again !" RESET<<std::endl;
				return -1;
			}
		}
	}
	if (info.length() == 0)
	{
		std::cout<<RED "❌ ERROR: Your input data is empty :(" RESET;
		std::cout<<std::endl;
		std::cout<<BLUE "Please, insert something !" RESET<<std::endl;
		return -1;
	}
	return 0;
}

bool is_all_digits(std::string str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		{
			return false;
        }
	}
	return true;
}

int	get_valid_data(std::string data[5])
{
	for (int index = 0; index < 5; index++)
	{
		print_input_place(index);
		getline(std::cin, data[index]);
		if (validate_input_data(data[index], index) == -1)
		return -1;
	}
	return 0;
}
