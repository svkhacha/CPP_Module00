/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:27:23 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:27:30 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "./Contact.hpp"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

class	PhoneBook
{
	public:
		PhoneBook();
		void	set_contact(std::string info[5]);
		void	get_contact(int contact_index);
		void	get_phonebook();
		void	get_phonebook_details(std::string info);
		int		get_phonebook_size();	

	private:
		Contact	m_contact[8];
		int		m_index;
		int		m_phonebook_size;
};

//validation.cpp
void	print_input_place(int index);
int		validate_input_data(std::string info, int index);
int		get_valid_data(std::string data[5]);
bool 	is_all_digits(std::string str);

#endif
