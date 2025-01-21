/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/21 18:13:49 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (!ft_alive_print_msg(philo, MSG_EAT))
		return ;
	pthread_mutex_lock(&philo->mutex_time);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->mutex_time);
	ft_wait(philo, philo->time_to_eat);
	philo->meals_eaten++;
	if (philo->meals_to_eat != -1 && !(philo->reached))
	{
		if (philo->meals_eaten == philo->meals_to_eat)
		{
			philo->reached = true;
			pthread_mutex_lock(&philo->table->mutex_meal);
			philo->table->meals_goal_each++;
			pthread_mutex_unlock(&philo->table->mutex_meal);
		}
	}
}

void	ft_sleep(t_philo *philo)
{
	if (ft_alive_print_msg(philo, MSG_SLEEP))
		ft_wait(philo, philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	if (ft_alive_print_msg(philo, MSG_THINK))
		usleep(500);
}

void	ft_take_fork(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	first_fork = ft_order_fork(philo, FIRST);
	second_fork = ft_order_fork(philo, SECOND);
	pthread_mutex_lock(&(philo->table->mutex_fork[first_fork]));
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK)
		|| philo->left_fork == philo->right_fork)
	{
		ft_solo_dining(philo);
		pthread_mutex_unlock(&philo->table->mutex_fork[first_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->table->mutex_fork[second_fork]);
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK))
	{
		pthread_mutex_unlock(&(philo->table->mutex_fork[second_fork]));
		pthread_mutex_unlock(&(philo->table->mutex_fork[first_fork]));
		return ;
	}
	ft_eat(philo);
	pthread_mutex_unlock(&philo->table->mutex_fork[second_fork]);
	pthread_mutex_unlock(&(philo->table->mutex_fork[first_fork]));
}
