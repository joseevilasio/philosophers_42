/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/05 21:34:50 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	printf(MSG_EAT, ft_get_time(), philo->id);
	usleep(philo->time_to_eat * 1000);
	philo->meals++;
	pthread_mutex_lock(&(philo->table)->mutex);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&(philo->table)->mutex);
	if (philo->meals == philo->meal_goal)
	{
		pthread_mutex_lock(&(philo->table)->mutex);
		philo->reached = 1;
		pthread_mutex_unlock(&(philo->table)->mutex);
	}
}

void	ft_sleep(t_philo *philo)
{
	printf(MSG_SLEEP, ft_get_time(), philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	printf(MSG_THINK, ft_get_time(), philo->id);
}

void	ft_die(t_philo *philo)
{
	printf(MSG_DIE, ft_get_time(), philo->id);
}

void	ft_take_fork(t_philo *philo)
{
	printf(MSG_TAKE_FORK, ft_get_time(), philo->id);
}
