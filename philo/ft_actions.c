/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:37 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/03 22:43:01 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	printf(MSG_EAT, ft_get_time(), philo->id);
	usleep(philo->time_to_eat * 1000);
	philo->meals++;
	philo->last_meal = ft_get_time();
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

void	ft_dead(t_philo *philo)
{
	printf(MSG_DEAD, ft_get_time(), philo->id);
}

void	ft_get_fork(t_philo *philo)
{
	printf(MSG_GET_FORK, ft_get_time(), philo->id);
}
