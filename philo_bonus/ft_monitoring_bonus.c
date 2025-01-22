/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/22 19:58:20 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philos)
	{
		sem_post(table->sem_go_on);
		i++;
	}
	if (table->philo)
		free(table->philo);
	if (table->pid)
		free(table->pid);
	free(table);
}

bool	ft_alive_print_msg(t_philo *philo, const char *msg)
{
	bool	alive;

	sem_wait(philo->table->sem_alive);
	alive = philo->is_alive;
	if (alive)
		printf(msg, ft_elapsed_time(philo->table->start_time), philo->id);
	sem_post(philo->table->sem_alive);
	return (alive);
}

void	*ft_monitoring(void *data)
{
	size_t	elapsed_meal_time;
	t_philo	*philo;

	philo = (t_philo *) data;
	while (1)
	{
		sem_wait(philo->table->sem_alive);
		elapsed_meal_time = ft_elapsed_time(philo->last_meal_time);
		if (elapsed_meal_time > philo->time_to_die && philo->is_alive)
		{
			philo->is_alive = false;
			printf(MSG_DIE, ft_elapsed_time(philo->table->start_time), \
				philo->id);
			sem_post(philo->table->sem_alive);
			ft_cleanup(philo->table);
			exit(0);
		}
		sem_post(philo->table->sem_alive);
		usleep(500);
	}
	return (NULL);
}
