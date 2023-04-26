/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:30:26 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:30:35 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

//setters

void	Contact::set_first_name(std::string first_name) {m_first_name = first_name;}
void	Contact::set_last_name(std::string last_name) {m_last_name = last_name;}
void	Contact::set_nickname(std::string nickname) {m_nickanme = nickname;}
void	Contact::set_phone_number(std::string phone_numbner) {m_phone_number = phone_numbner;}
void	Contact::set_darkest_secret(std::string darkest_secret) {m_darkest_secret = darkest_secret;}

//getters

std::string	Contact::get_first_name() {return m_first_name;}
std::string	Contact::get_last_name() {return m_last_name;}
std::string	Contact::get_nickname() {return m_nickanme;}
std::string	Contact::get_phone_number() {return m_phone_number;}
std::string	Contact::get_darkest_secret() {return m_darkest_secret;}
