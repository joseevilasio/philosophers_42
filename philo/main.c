/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/03 22:47:26 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo));
	philos->meals = 0;
	philos->id = 1;
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	philos->meal_goal = ft_atoi(argv[5]);
	if (ft_parser(argc, argv) != 0)
		return (2);
	// if (ft_init() != 0)
	//	return (2);
	// if (usleep(LONG_MAX) == -1)
	// 	printf("error usleep\n");
	printf("%lu\n", ft_get_time());
	printf("Starting... \n");
	
	//usleep(ft_atol(argv[1]));
	while (1)
	{
		ft_get_fork(philos);
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
		usleep(200*1000);
		if (ft_elapsed_time(philos->last_meal) >= philos->time_to_die)
		{
			printf("elapsed time: %lu\n", (ft_elapsed_time(philos->last_meal)));
			ft_dead(philos);
			break ;
		}
		if (philos->meals >= philos->meal_goal)
		{
			printf("Meal Goal\n");
			break ;
		}
	}
	printf("%lu\n", ft_get_time());
	return (0);
}
