/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:08:36 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/04 18:03:01 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_create_philo(int argc, char **argv, int id, t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
	{
		printf("Error: malloc philo\n");
		return (NULL);
	}
	philo->id = id;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->meal_goal = ft_atoi(argv[5]);
	else
		philo->meal_goal = 0; //TODO
	philo->meals = 0;
	philo->last_meal = 0;
	philo->table;
	return (philo);
}

t_philo	**ft_init_philos(int argc, char **argv, t_table *table)
{
	t_philo	**philos;
	int		i;
	int		len;

	len = ft_atoi(argv[1]);
	i = 0;
	philos = (t_philo **) malloc((len + 1) * sizeof(t_philo *));
	if (!philos)
	{
		printf("Error: malloc philos\n");
		return (NULL);
	}
	while (i <= len)
	{
		philos[i] = ft_create_philo(argc, argv, i + 1, table);
		//if () erro no create //TODO
		i++;
	}
	philos[i] = NULL;
	return (philos);
}

t_table	*ft_init_table(t_philo **philos)
{
	t_table	*table;

	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
	{
		printf("Error: malloc philos\n");
		return (NULL);
	}
	table->philos = NULL;
	return (table);
}
