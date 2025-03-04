/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:08:36 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/11 21:26:58 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_create_philo(int argc, char **argv, int id, t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (printf("Error: malloc philo\n"), NULL);
	philo->id = id;
	philo->meals_eaten = 0;
	philo->meals_to_eat = -1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->reached = false;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % table->number_of_philos;
	philo->last_meal_time = table->start_time;
	philo->table = table;
	if (argc == 6)
		philo->meals_to_eat = ft_atoi(argv[5]);
	table->meals_goal = philo->meals_to_eat;
	pthread_mutex_init(&philo->mutex_time, NULL);
	return (philo);
}

static t_philo	**ft_init_philos(int argc, char **argv, t_table *table)
{
	t_philo	**philos;
	int		i;
	int		number_of_philo;

	number_of_philo = ft_atoi(argv[1]);
	i = 0;
	philos = (t_philo **) malloc((number_of_philo + 1) * sizeof(t_philo *));
	if (!philos)
		return (printf("Error: malloc philos\n"), NULL);
	while (i < number_of_philo)
	{
		philos[i] = ft_create_philo(argc, argv, i, table);
		if (!philos[i])
			return (printf("Error: malloc philos\n"), NULL);
		i++;
	}
	philos[i] = NULL;
	return (philos);
}

static pthread_mutex_t	*ft_init_mutex(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) \
		* table->number_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_table	*ft_init(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
		return (printf("Error: malloc table\n"), NULL);
	table->number_of_philos = ft_atoi(argv[1]);
	table->meals_goal = -1;
	table->meals_goal_each = 0;
	table->meals_goal_reached = false;
	table->all_alive = true;
	table->start_time = ft_get_time();
	table->mutex_fork = ft_init_mutex(table);
	if (!table->mutex_fork)
		return (free(table), NULL);
	table->philos = ft_init_philos(argc, argv, table);
	if (!table->philos)
		return (free(table->mutex_fork), free(table), NULL);
	pthread_mutex_init(&table->mutex_alive, NULL);
	pthread_mutex_init(&table->mutex_meal, NULL);
	return (table);
}
