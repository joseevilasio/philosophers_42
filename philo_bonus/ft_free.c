/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:30 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/11 20:33:44 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_mutex_destroy(t_table *table, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_destroy(&table->mutex_fork[i]);
		i++;
	}
}

static void	ft_free_philos(t_philo **philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_destroy(&(philos[i])->mutex_time);
		free(philos[i]);
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
		if (table->mutex_fork)
		{
			ft_mutex_destroy(table, table->number_of_philos);
			free(table->mutex_fork);
		}
		pthread_mutex_destroy(&table->mutex_alive);
		pthread_mutex_destroy(&table->mutex_meal);
		free(table);
	}
}
