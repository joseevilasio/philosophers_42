/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:17:58 by joneves-          #+#    #+#             */
/*   Updated: 2024/12/31 18:00:19 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_valid_arguments(int argc, char **argv)
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
