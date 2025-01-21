/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:28 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:31 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (1)
	{
		if (!ft_check_everything(philo->table))
			break ;
		ft_take_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (!ft_check_everything(philo->table))
			break ;
	}
	return (NULL);
}

int	ft_start_dinner(t_table *table, t_philo **philos)
{
	pthread_t	*threads;
	int			i;

	threads = (pthread_t *) malloc(table->number_of_philos * sizeof(pthread_t));
	if (!threads)
		return (printf("Error: malloc threads\n"), 1);
	i = 0;
	while (i < table->number_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &ft_routine, philos[i]) != 0)
			return (free(threads), printf("Error: pthread create\n"), 1);
		i++;
	}
	ft_monitoring(table);
	i = 0;
	while (i < table->number_of_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (free(threads), printf("Error: pthread join\n"), 1);
		i++;
	}
	return (free(threads), 0);
}
