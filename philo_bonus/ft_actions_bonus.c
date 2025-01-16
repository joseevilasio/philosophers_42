/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/16 14:56:27 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	if (!ft_alive_print_msg(philo, MSG_EAT))
		return ;
	sem_wait(philo->table->sem_alive);
	philo->last_meal_time = ft_get_time();
	sem_post(philo->table->sem_alive);
	ft_wait(philo, philo->time_to_eat);
	sem_wait(philo->table->sem_alive);
	philo->meals_eaten++;
	sem_post(philo->table->sem_alive);
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
	sem_wait(philo->table->sem_forks);
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK))
	{
		sem_post(philo->table->sem_forks);
		return ;
	}
	sem_wait(philo->table->sem_forks);
	if (!ft_alive_print_msg(philo, MSG_TAKE_FORK))
	{
		sem_post(philo->table->sem_forks);
		sem_post(philo->table->sem_forks);
		return ;
	}
	ft_eat(philo);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_forks);
}
