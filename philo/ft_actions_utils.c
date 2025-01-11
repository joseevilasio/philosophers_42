/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/11 21:21:36 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(t_philo *philo, size_t time)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
	{
		pthread_mutex_lock(&philo->table->mutex_alive);
		if (!philo->table->all_alive)
		{
			pthread_mutex_unlock(&philo->table->mutex_alive);
			break ;
		}
		pthread_mutex_unlock(&philo->table->mutex_alive);
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
