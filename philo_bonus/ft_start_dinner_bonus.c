/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/22 18:33:19 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_dinner_is_over(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philos)
	{
		sem_wait(table->sem_go_on);
		i++;
	}
	i = 0;
	while (i < table->number_of_philos)
	{
		kill(table->pid[i], SIGKILL);
		i++;
	}
}

static void	ft_wait_child(void)
{
	while (1)
	{
		if (waitpid(-1, NULL, 0) == -1)
			break ;
	}
}

void	ft_routine(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &ft_monitoring, philo) != 0)
		printf("Error: pthread create\n");
	pthread_detach(monitor);
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (1)
	{
		ft_take_fork(philo);
		if (philo->meals_eaten == philo->meals_to_eat)
			sem_post(philo->table->sem_go_on);
		ft_sleep(philo);
		ft_think(philo);
	}
}

int	ft_start_dinner(t_table *table)
{
	int	i;

	table->pid = (pid_t *) malloc(sizeof(pid_t) * table->number_of_philos);
	if (!table->pid)
		return (printf("Error: malloc pid\n"), 1);
	i = 0;
	while (i < table->number_of_philos)
	{
		table->philo->id = i + 1;
		table->pid[i] = fork();
		if (table->pid[i] == -1)
			return (printf("Error: fork\n"), 1);
		if (table->pid[i] == 0)
			ft_routine(table->philo);
		i++;
	}
	ft_dinner_is_over(table);
	ft_wait_child();
	return (0);
}
