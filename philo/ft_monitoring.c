/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/11 21:28:39 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_alive_print_msg(t_philo *philo, const char *msg)
{
	if (!ft_check_everything(philo->table))
		return (false);
	printf(msg, ft_elapsed_time(philo->table->start_time), philo->id + 1);
	return (true);
}

bool	ft_check_everything(t_table *table)
{
	bool	is_all_alive;
	bool	is_goal_reached;

	pthread_mutex_lock(&table->mutex_alive);
	pthread_mutex_lock(&table->mutex_meal);
	is_all_alive = table->all_alive;
	is_goal_reached = table->meals_goal_reached;
	pthread_mutex_unlock(&table->mutex_meal);
	pthread_mutex_unlock(&table->mutex_alive);
	return (is_all_alive && !is_goal_reached);
}

static bool	ft_is_alive(t_table *table, t_philo *philo)
{
	bool	is_alive;
	size_t	last_meal_time;

	is_alive = true;
	pthread_mutex_lock(&philo->mutex_time);
	last_meal_time = ft_elapsed_time(philo->last_meal_time);
	if (last_meal_time > philo->time_to_die)
	{
		printf(MSG_DIE, ft_elapsed_time(table->start_time), philo->id + 1);
		pthread_mutex_lock(&table->mutex_alive);
		table->all_alive = false;
		pthread_mutex_unlock(&table->mutex_alive);
		is_alive = false;
	}
	pthread_mutex_unlock(&philo->mutex_time);
	return (is_alive);
}

static bool	ft_meals_goal(t_table *table)
{
	bool	go_on;

	go_on = true;
	pthread_mutex_lock(&table->mutex_meal);
	if (table->meals_goal != -1
		&& table->meals_goal_each >= table->number_of_philos)
	{
		table->meals_goal_reached = true;
		go_on = false;
	}
	pthread_mutex_unlock(&table->mutex_meal);
	return (go_on);
}

void	ft_monitoring(t_table *table)
{
	int		i;
	bool	go_on;

	go_on = true;
	while (go_on)
	{
		i = 0;
		while ((table->philos)[i])
		{
			if (!ft_is_alive(table, (table->philos)[i])
				|| !ft_meals_goal(table))
			{
				go_on = false;
				break ;
			}
			i++;
		}
		usleep(500);
	}
}
