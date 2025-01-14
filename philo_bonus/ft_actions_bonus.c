/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/14 20:09:40 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	if (!ft_alive_print_msg(philo, MSG_EAT))
		return ;
	philo->meals_eaten++;
	sem_wait(philo->sem_time);
	philo->last_meal_time = ft_get_time();
	sem_post(philo->sem_time);
	if (philo->meals_to_eat != -1 && !(philo->reached))
	{
		if (philo->meals_eaten == philo->meals_to_eat)
		{
			philo->reached = true;
			sem_wait(philo->table->sem_meal);
			philo->table->meals_goal_each++;
			sem_post(philo->table->sem_meal);
		}
	}
	ft_wait(philo, philo->time_to_eat);
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

	if (philo->left_fork == philo->right_fork)
		ft_solo_dining(philo);
	first_fork = ft_order_fork(philo, FIRST);
	second_fork = ft_order_fork(philo, SECOND);
	sem_wait((philo->table->sem_fork[first_fork]));
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK))
	{
		sem_post((philo->table->sem_fork[first_fork]));
		return ;
	}
	sem_wait((philo->table->sem_fork[second_fork]));
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK))
	{
		sem_post((philo->table->sem_fork[first_fork]));
		sem_post((philo->table->sem_fork[second_fork]));
		return ;
	}
	ft_eat(philo);
	sem_post((philo->table->sem_fork[second_fork]));
	sem_post((philo->table->sem_fork[first_fork]));
}
