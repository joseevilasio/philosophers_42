/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/07 23:02:54 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	printf(MSG_EAT, ft_get_time(), philo->id);
	usleep((philo->table)->time_to_eat * 1000);
	philo->fork = 0; //without a fork | maybe mutex
	pthread_mutex_lock(&philo->table->mutex_meal);
	philo->meals++;
	philo->last_meal = ft_get_time();
	if (philo->meal_goal != 0)
	{
		if (philo->meals == philo->meal_goal)
			philo->table->meal_goal_each++;
	}
	pthread_mutex_unlock(&philo->table->mutex_meal);
}

void	ft_sleep(t_philo *philo)
{
	printf(MSG_SLEEP, ft_get_time(), philo->id);
	usleep(philo->table->time_to_sleep * 1000);
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
	int	next;
	
	next = philo->id + 1;
	//mutex lock
	philo->fork == 1; // try take a fork
	if (!philo->table->philos[next])
		next = 0;
	(philo->table->philos[next])->fork = 1;
	//eu tenho um garfo
	// ft eat
	//unlock
	
	printf(MSG_TAKE_FORK, ft_get_time(), philo->id);
}
