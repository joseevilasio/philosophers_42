/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:30 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/13 21:52:50 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	ft_mutex_destroy(t_table *table, int number_of_philos)
// {
// 	int	i;

// 	i = 0;
// 	while (i < number_of_philos)
// 	{
// 		pthread_mutex_destroy(&table->mutex_fork[i]);
// 		i++;
// 	}
// }

static void	ft_sem_destroy(t_table *table, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		sem_unlink(table->sem_fork_ref[i]);
		free(table->sem_fork_ref[i]);
		i++;
	}
	free(table->sem_fork_ref);
}

static void	ft_free_philos(t_philo **philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		//pthread_mutex_destroy(&(philos[i])->mutex_time);
		sem_unlink((philos[i])->sem_time_ref); //TODO criar nome unico para cada
		free((philos[i])->sem_time_ref);
		i++;
	}
}

void	ft_free(t_table *table)
{
	if (table)
	{
		if (table->philos)
		{
			ft_free_philos(table->philos, table->number_of_philos);
			free(table->philos);
		}
		if (table->sem_fork)
		{
			//ft_mutex_destroy(table, table->number_of_philos);
			ft_sem_destroy(table, table->number_of_philos);
			//free(table->mutex_fork);
			free(table->sem_fork); //TODO
		}
		// pthread_mutex_destroy(&table->mutex_alive);
		// pthread_mutex_destroy(&table->mutex_meal);
		sem_unlink("/sem_alive");
		sem_unlink("/sem_meal");
		free(table);
	}
}
