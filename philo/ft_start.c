/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/07 21:10:21 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_alive(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->mutex_meal);
	if (philo->last_meal != 0
		&& ft_elapsed_time(philo->last_meal) >= table->time_to_die)
	{
		printf("--> %lu\n", ft_elapsed_time((philo->last_meal))); //debug
		ft_die(philo);
		pthread_mutex_lock(&table->mutex_alive);
		table->all_alive = 0;
		pthread_mutex_unlock(&table->mutex_alive);
	}
	pthread_mutex_unlock(&table->mutex_meal);
}

void	ft_check_meal(t_table *table)
{
	int	meal_goal_each;

	pthread_mutex_lock(&table->mutex_meal);
	meal_goal_each = table->meal_goal_each;
	pthread_mutex_unlock(&table->mutex_meal);
	if (table->meal_goal != 0
		&& meal_goal_each == table->number_of_philos)
	{
		pthread_mutex_lock(&table->mutex_alive);
		table->all_alive = 0;
		pthread_mutex_unlock(&table->mutex_alive);
	}
}

void	*ft_monitoring(void *data)
{
	t_table	*table;
	int		i;
	int		all_alive;

	table = (t_table *) data;
	while (1)
	{
		i = 0;
		while ((table->philos)[i])
		{
			ft_check_alive(table, (table->philos)[i]);
			ft_check_meal(table);
			i++;
		}
		pthread_mutex_lock(&table->mutex_alive);
		all_alive = table->all_alive;
		pthread_mutex_unlock(&table->mutex_alive);
		if (all_alive == 0)
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;
	int		all_alive;

	philo = (t_philo *) data;
	while (1)
	{
		ft_think(philo);
		ft_take_fork(philo); //se ocorrer pare de pensar e avanca
		ft_eat(philo);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->table->mutex_alive);
		all_alive = philo->table->all_alive;
		pthread_mutex_unlock(&philo->table->mutex_alive);
		if (all_alive == 0)
			break ;
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
		return ;
	}
	i = 0;
	if (pthread_create(&t_monitoring, NULL, &ft_monitoring, table) != 0)
	{
		printf("Error: pthread create\n");
		free(threads);
		return ;
	}
	while (i < table->number_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &ft_routine, philos[i]) != 0)
		{
			printf("Error: pthread create\n");
			// free em threads ja criadas
			return ;
		}
		printf("Thread %d has started\n", i); //debug
		i++;
	}
	i = 0;
	if (pthread_join(t_monitoring, NULL) != 0)
		printf("Error\n");
	while (i < table->number_of_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			printf("Error\n");//return (printf("Error\n"), 1);
		printf("Thread %d has finished\n", i); //debug
		i++;
	}
	//free threads
}
