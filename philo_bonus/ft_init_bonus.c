/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:08:36 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/16 14:55:08 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*ft_init_philo(int argc, char **argv, t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (printf("Error: malloc philo\n"), NULL);
	philo->id = 0;
	philo->meals_eaten = 0;
	philo->meals_to_eat = -1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->is_alive = true;
	philo->last_meal_time = table->start_time;
	philo->table = table;
	if (argc == 6)
		philo->meals_to_eat = ft_atoi(argv[5]);
	return (philo);
}

static int	ft_init_sem(t_table *table)
{
	sem_unlink("/sem_alive");
	table->sem_alive = sem_open("/sem_alive", O_CREAT, 0644, 1);
	if (table->sem_alive == SEM_FAILED)
		return (-1);
	sem_unlink("/sem_go_on");
	table->sem_go_on = sem_open("/sem_go_on", O_CREAT, 0644, 0);
	if (table->sem_go_on == SEM_FAILED)
		return (-1);
	sem_unlink("/sem_forks");
	table->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, \
		table->number_of_philos);
	if (table->sem_forks == SEM_FAILED)
		return (-1);
	return (0);
}

t_table	*ft_init(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
		return (printf("Error: malloc table\n"), NULL);
	table->number_of_philos = ft_atoi(argv[1]);
	table->start_time = ft_get_time();
	if (ft_init_sem(table) != 0)
		return (free(table), NULL);
	table->philo = ft_init_philo(argc, argv, table);
	if (!table->philo)
		return (ft_free(table), NULL);
	return (table);
}
