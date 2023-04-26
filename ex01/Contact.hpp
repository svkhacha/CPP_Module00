/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:27:49 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:28:00 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP
#include <string>
#include "./PhoneBook.hpp"

class	Contact
{
	public:
		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nickname(std::string nickname);
		void	set_phone_number(std::string phone_number);
		void	set_darkest_secret(std::string darkest_secret);

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();

	private:
		std::string	m_first_name;
		std::string	m_last_name;
		std::string	m_nickanme;
		std::string	m_phone_number;
		std::string	m_darkest_secret;
};

#endif

