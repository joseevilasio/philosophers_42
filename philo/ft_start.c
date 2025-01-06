/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/05 22:00:35 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *) data;
	while (1)
	{
		i = 0;
		while ((table->philos)[i])
		{
			if (((table->philos)[i])->last_meal != 0
				&& ft_elapsed_time(((table->philos)[i])->last_meal) >= ((table->philos)[i])->time_to_die)
			{
				printf("elapsed time: %lu\n", \
					((((table->philos)[i])->last_meal)));
				ft_die(((table->philos)[i]));
				pthread_mutex_lock(&table->mutex);
				table->go_on = 0;
				//break ;
				pthread_mutex_unlock(&table->mutex);
			}
			pthread_mutex_lock(&table->mutex);
			if (((table->philos)[i])->reached == 1)
			{
				table->meal_goal_each++;
				//printf("Meal Goal - Philo %d\n", ((table->philos)[i])->id);
			}
			if (table->meal_goal_each == table->number_of_philos)
				table->go_on = 0;
			pthread_mutex_unlock(&table->mutex);
			i++;
		}
		pthread_mutex_lock(&table->mutex);
		if (table->go_on == 0)
		{
			pthread_mutex_unlock(&table->mutex);
			break ;
		}
		pthread_mutex_unlock(&table->mutex);
	}
	return (NULL);
}

void	*ft_routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *) data;
	while (1)
	{
		ft_think(philo);
		ft_take_fork(philo); //se ocorrer pare de pensar e avanca
		ft_eat(philo);
		ft_sleep(philo);
		//usleep(100*1000);
		pthread_mutex_lock(&(philo->table)->mutex);
		if ((philo->table)->go_on == 0)
		{
			pthread_mutex_unlock(&(philo->table)->mutex);
			break ;
		}
		pthread_mutex_unlock(&(philo->table)->mutex);
	}
	return (NULL);
}

void	ft_start(t_table *table, t_philo **philos)
{
	pthread_t	*threads;
	pthread_t	t_monitoring;
	int			i;

	threads = (pthread_t *) malloc(table->number_of_philos * sizeof(pthread_t));
	if (!threads)
	{
		printf("Error: malloc threads\n");
		//return (NULL);
	}
	i = 0;
	while (i < table->number_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &ft_routine, philos[i]) != 0)
			printf("Error: pthread create\n");//return (printf("Error: pthread create\n"), 1);
		printf("Thread %d has started\n", i); //debug
		i++;
		if (i == table->number_of_philos)
		{
			if (pthread_create(&t_monitoring, NULL, &ft_monitoring, table) != 0)
				printf("Error: pthread create\n");
		}
	}
	i = 0;
	while (i < table->number_of_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			printf("Error\n");//return (printf("Error\n"), 1);
		printf("Thread %d has finished\n", i); //debug
		i++;
		if (i == table->number_of_philos)
			if (pthread_join(t_monitoring, NULL) != 0)
				printf("Error\n");
	}
}
