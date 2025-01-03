/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:17:58 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/03 22:21:38 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_valid_argument(char *argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
		{
			printf("Error: %s: numeric argument required\n", argv);
			return (-1);
		}
		i++;
	}
	nbr = ft_atol(argv);
	if (nbr < 1 || nbr > INT_MAX)
		return (printf("Error: %s: numeric argument required\n", argv), -1);
	return (0);
}

int	ft_parser(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
		return (printf("Error: missing arguments\n"), -1);
	if (argc > 6)
		return (printf("Error: too many arguments\n"), -1);
	while (argv[i])
	{
		if (ft_valid_argument(argv[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
