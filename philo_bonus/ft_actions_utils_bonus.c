/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/14 20:09:41 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_wait(t_philo *philo, size_t time)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
	{
		sem_wait(philo->table->sem_alive);
		if (!philo->table->all_alive)
		{
			sem_post(philo->table->sem_alive);
			break ;
		}
		sem_post(philo->table->sem_alive);
		usleep(500);
	}
}

void	ft_solo_dining(t_philo *philo)
{
	ft_alive_print_msg(philo, MSG_TAKE_FORK);
	ft_wait(philo, philo->time_to_die);
}

int	ft_order_fork(t_philo *philo, int which)
{
	int	index;

	if (which == FIRST)
	{
		if (philo->left_fork < philo->right_fork)
			index = philo->left_fork;
		else
			index = philo->right_fork;
	}
	if (which == SECOND)
	{
		if (philo->left_fork < philo->right_fork)
			index = philo->right_fork;
		else
			index = philo->left_fork;
	}
	return (index);
}
