/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:25:23 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:25:32 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else{
        for (int i = 1; argv[i]; ++i)
        {
            for (int j = 0; argv[i][j]; ++j)
            {
                std::cout<<(char)toupper(argv[i][j]);
            }
            std::cout<<" ";
        }
    }
      std::cout<<std::endl;
}
