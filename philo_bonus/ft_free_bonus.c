/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:30 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/16 14:44:31 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free(t_table *table)
{
	if (table)
	{
		if (table->philo)
		{
			free(table->philo);
		}
		if (table->pid)
			free(table->pid);
		if (table->sem_alive)
		{
			sem_close(table->sem_alive);
			sem_unlink("/sem_alive");
		}
		if (table->sem_go_on)
		{
			sem_close(table->sem_go_on);
			sem_unlink("/sem_go_on");
		}
		if (table->sem_forks)
		{
			sem_close(table->sem_forks);
			sem_unlink("/sem_forks");
		}
		free(table);
	}
}
