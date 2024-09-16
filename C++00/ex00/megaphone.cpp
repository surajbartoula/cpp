/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:17:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/12 18:26:22 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	toUpper(char **argv)
{
	int i;
	
	i = 0;
	while ((*argv)[i])
	{
		if ((*argv)[i] >= 'a' && (*argv)[i] <= 'z')
			(*argv)[i] -= 32;
		i++;
	}
}

int	 main(int argc, char **argv)
{
	int i;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			toUpper(&argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}
