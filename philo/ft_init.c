/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:08:36 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/07 19:27:20 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_create_philo(int argc, char **argv, int id, t_table *table)
{
	t_philo	*philo;
	(void)argc; //TODO

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
	{
		printf("Error: malloc philo\n");
		return (NULL);
	}
	philo->id = id;
	philo->meals = 0;
	philo->reached = 0;
	philo->fork = 1;
	philo->last_meal = 0;
	philo->table = table;
	if (argc == 6)
		philo->meal_goal = ft_atoi(argv[5]);
	else
		philo->meal_goal = 0; //TODO
	table->meal_goal = philo->meal_goal; //TODO
	return (philo);
}

t_philo	**ft_init_philos(int argc, char **argv, t_table *table)
{
	t_philo	**philos;
	int		i;
	int		number_of_philo;

	number_of_philo = ft_atoi(argv[1]);
	i = 0;
	philos = (t_philo **) malloc((number_of_philo + 1) * sizeof(t_philo *));
	if (!philos)
	{
		printf("Error: malloc philos\n");
		return (NULL);
	}
	while (i <= number_of_philo)
	{
		philos[i] = ft_create_philo(argc, argv, i + 1, table);
		//if () erro no create //TODO
		i++;
	}
	philos[i] = NULL;
	table->philos = philos;
	table->number_of_philos = number_of_philo;
	return (philos);
}

t_table	*ft_init_table(int argc, char **argv, t_philo **philos)
{
	t_table	*table;
	(void)argc;
	(void)argv;

	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
	{
		printf("Error: malloc table\n");
		return (NULL);
	}
	pthread_mutex_init(&table->mutex_meal, NULL);
	pthread_mutex_init(&table->mutex_alive, NULL);
	table->number_of_philos = 0;
	table->all_alive = 1;
	table->philos = philos;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	return (table);
}
