/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/03 19:28:25 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (ft_parser(argc, argv) != 0)
		return (2);
	// if (ft_init() != 0)
	//	return (2);
	// if (usleep(LONG_MAX) == -1)
	// 	printf("error usleep\n");
	printf("%lu\n", ft_get_time());
	
	usleep(ft_atol(argv[1]));

	printf("%lu\n", ft_get_time());
	printf("Starting... \n");
	return (0);
}
