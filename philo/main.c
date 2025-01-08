/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/07 19:28:05 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			**philos;
	t_table			*table;

	philos = NULL;
	table = NULL;
	if (ft_parser(argc, argv) != 0)
		return (2);
	table = ft_init_table(argc, argv, philos);
	if (!table)
		return (1);
	philos = ft_init_philos(argc, argv, table);
	if (!philos)
		return (1);
	printf("%lu\n", ft_get_time()); //debug
	printf("Starting... \n"); //debug
	ft_start(table, philos);
	printf("%lu\n", ft_get_time()); //debug
	pthread_mutex_destroy(&table->mutex_meal);
	pthread_mutex_destroy(&table->mutex_alive);
	return (0);
}
