/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2024/12/31 17:28:34 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo/philo.h"

long	mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i;

	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(/* int argc, char **argv */)
{
	pthread_t	thread[10];
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);

	while (i < 10)
	{
		if (pthread_create(thread + i, NULL, &routine, NULL) != 0)
			return (printf("Error\n"), 1);
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(thread[i], NULL) != 0)
		return (printf("Error\n"), 1);
		printf("Thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Emails: %ld\n", mails);
	return (0);
}
