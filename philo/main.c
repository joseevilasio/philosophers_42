/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/04 18:03:44 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_table	*table;

	if (ft_parser(argc, argv) != 0)
		return (2);
	philos = ft_init_philos(argc, argv, table);
	if (!philos)
		return (1);
	printf("%lu\n", ft_get_time()); //debug
	printf("Starting... \n"); //debug

	while (1)
	{
		ft_get_fork(philos[0]);
		ft_eat(philos[0]);
		ft_sleep(philos[0]);
		ft_think(philos[0]);
		usleep(400*1000);
		if (ft_elapsed_time(philos[0]->last_meal) >= philos[0]->time_to_die)
		{
			printf("elapsed time: %lu\n", (ft_elapsed_time(philos[0]->last_meal)));
			ft_dead(philos[0]);
			break ;
		}
		if (philos[0]->meals >= philos[0]->meal_goal)
		{
			printf("Meal Goal\n");
			break ;
		}
	}
	printf("%lu\n", ft_get_time());
	return (0);
}
