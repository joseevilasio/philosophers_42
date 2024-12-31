/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:51 by joneves-          #+#    #+#             */
/*   Updated: 2024/12/31 17:19:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

int	ft_valid_arguments(int argc, char **argv);

/* External functs.

string.h
	menset

stdio.h
	printf

stdlib.h
	malloc | free

unistd.h
	write | usleep

sys/time.h
	gettimeofday

pthread.h
	pthread_create | pthread_detach | pthread_join | pthread_mutex_init
	pthread_mutex_destroy | pthread_mutex_lock | pthread_mutex_unlock
*/

#endif //PHILO_H