/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2024/12/31 18:28:10 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	if (ft_valid_arguments(argc, argv) != 0)
		return (2);
	if (usleep(LONG_MAX) == -1)
		printf("error usleep\n");
	perror("usleep: ");
	printf("Starting... \n");
	return (0);
}
