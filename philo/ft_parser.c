/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:17:58 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/02 19:27:54 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_valid_argument()
{
	
}

int	ft_parser(int argc, char **argv)
{
	int	i;
	int	z;

	i = 1;
	if (argc < 4)
		return (printf("Error: missing arguments\n"), -1);
	if (argc > 5)
		return (printf("Error: too many arguments\n"), -1);
	while (argv[i])
	{
		z = 0;
		while (argv[i][z])
		{
			if (ft_isdigit(argv[i][z]) == 0)
			{
				printf("Error: %s: numeric argument required\n", argv[i]);
				return (-1);
			}
			z++;
		}
		i++;
	}
	return (0);
}
