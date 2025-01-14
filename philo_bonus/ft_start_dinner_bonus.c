/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/14 20:24:51 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_routine(t_philo *philo)
{
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (1)
	{
		if (!ft_is_alive(philo->table, philo))
			break ;
		ft_take_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (!ft_is_alive(philo->table, philo))
			break ;
	}
}

int	ft_start_dinner(t_table *table, t_philo **philos)
{
	int	i;
	(void)philos;

	table->pid = (pid_t *) malloc(sizeof(pid_t) * table->number_of_philos);
	if (!table->pid)
		return (printf("Error: malloc pid\n"), 1);
	i = 0;
	while (i < table->number_of_philos)
	{
		table->pid[i] = fork();
		if (table->pid[i] == -1)
			return (printf("Error: fork\n"), 1);
		if (table->pid[i] == 0)
			ft_routine(table->philos[i]);
		ft_monitoring(table);
		i++;
	}
	return (0);
}
