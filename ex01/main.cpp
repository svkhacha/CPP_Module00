/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:41 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:31:51 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook 	phonebook;
	std::string	input_data;
	std::string	contact_data[5];
	std::string contact_index;

	std::cout<<std::endl;
	std::cout <<CYAN "\t \t \t \tWelcome to MY AWESOME PHONEBOOK 👋" RESET<< std::endl;
	while (1)
	{
		std::cout<<std::endl<<BLUE "Please, choose one of these commands 👇" RESET<<std::endl;
		std::cout<<"ADD, SEARCH or EXIT: ";
		getline(std::cin, input_data);
		if (std::cin.eof())
			break ;
		if (input_data.compare("ADD") == 0)
		{
			std::cout<<BLUE "Now, you can add new contact details 📱 !" RESET<<std::endl;
			std::cout<<std::endl;
			if (get_valid_data(contact_data) == -1)
			{
				continue ;
			}
			phonebook.set_contact(contact_data);
			std::cout<<GREEN "✅ Your new contact added successfully !" RESET<<std::endl;
		}
		else if (input_data.compare("SEARCH") == 0)
		{
			phonebook.get_phonebook();
			std::cout<<std::endl;
			std::cout<<BLUE "Insert the contact index to see in details: " RESET;
			//std::cin>>contact_index;
			std::getline(std::cin, contact_index);
			if (std::cin.eof())
				break ;
			if (atoi(contact_index.c_str()) < 0 || atoi(contact_index.c_str())>= phonebook.get_phonebook_size()
				|| !is_all_digits(contact_index))
			{
				std::cout<<RED "  ❌ ERROR: No contact has found with given index :(" RESET<<std::endl; 
				std::cout<< RED "OR" RESET<<std::endl;
				std::cout<< RED "  Your input contains alphabetic characters :(" RESET<<std::endl;
				std::cout<<std::endl;
				std::cout<<BLUE "Please, check your input data, try again !" RESET<<std::endl;
				//std::cin.ignore(input_data.length(), '\n');
				continue ;
			}
			phonebook.get_contact(std::atoi(contact_index.c_str()));
			//std::cin.ignore(input_data.length(), '\n');
		}
		else if (input_data.compare("EXIT") == 0)
		{
			std::cout<<BLUE "Are sure, you want to leave PhoneBook ? [Y/n]" RESET<<std::endl;
			getline(std::cin, input_data);
			if (std::cin.eof())
				break ;
			if (input_data.compare("Y") == 0)
				break ;
			else
				continue ;
		}
	}
	return 0;
}
