/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/02 18:14:23 by joneves-         ###   ########.fr       */
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
	printf("Starting... \n");
	return (0);
}
