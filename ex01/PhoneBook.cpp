/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:27:08 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:27:13 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() {m_phonebook_size= 0; m_index = 0;}

void	PhoneBook::set_contact(std::string info[5])
{
	m_contact[m_index].set_first_name(info[0]);
	m_contact[m_index].set_last_name(info[1]);
	m_contact[m_index].set_nickname(info[2]);
	m_contact[m_index].set_phone_number(info[3]);
	m_contact[m_index].set_darkest_secret(info[4]);
	m_index++;
	if (m_index > 7)
		m_index = 0;
	if (m_phonebook_size < 8)
		m_phonebook_size++;
}

void	PhoneBook::get_contact(int contact_index)
{
	std::cout<<std::endl;
	std::cout<<CYAN "🔹First Name: " RESET<<m_contact[contact_index].get_first_name();
	std::cout<<std::endl;
	std::cout<<CYAN "🔹Last Name: " RESET<<m_contact[contact_index].get_last_name();
	std::cout<<std::endl;
	std::cout<<CYAN "🔹Nickname: " RESET<<m_contact[contact_index].get_nickname();
	std::cout<<std::endl;
	std::cout<<CYAN "🔹Phone Number: " RESET<<m_contact[contact_index].get_phone_number();
	std::cout<<std::endl;
	std::cout<<CYAN "🔹Darkest Secret: " RESET<<m_contact[contact_index].get_darkest_secret();
	std::cout<<std::endl;
}

void	PhoneBook::get_phonebook_details(std::string info)
{
	if (info.length() > 10)
		std::cout<<info.substr(0, 9)<<"."<<CYAN "|" RESET;
	else
		std::cout<<std::setw(10)<<info<<CYAN "|" RESET;
}

void	PhoneBook::get_phonebook()
{
	std::cout<<std::endl;
	std::cout<<CYAN "|"<<std::setw(10)<<"Index"<<"|" RESET;
	std::cout<<CYAN<<std::setw(10)<<"First Name"<<"|" RESET;
	std::cout<<CYAN<<std::setw(10)<<"Last Name"<<"|" RESET;
	std::cout<<CYAN<<std::setw(10)<<"Nickname"<<"|" RESET;
	std::cout<<std::endl;
	for (int index = 0; index < m_phonebook_size; index++)
	{
		std::cout<<CYAN "|" RESET<<std::setw(10)<<index<<CYAN "|" RESET;
		get_phonebook_details(m_contact[index].get_first_name());
		get_phonebook_details(m_contact[index].get_last_name());
		get_phonebook_details(m_contact[index].get_nickname());
		std::cout<<std::endl;
	}
}

int	PhoneBook::get_phonebook_size() {return m_phonebook_size;}

