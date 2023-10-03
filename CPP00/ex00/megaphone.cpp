/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonim <jonim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:16:00 by jonim             #+#    #+#             */
/*   Updated: 2023/09/14 19:29:09 by jonim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		char *str;
		str = av[i];
		while (*str)
		{
			std::cout << (char)std::toupper(*str);
			str++;
		}
		if (i + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
}