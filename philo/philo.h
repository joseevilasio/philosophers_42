/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:51 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/03 19:28:47 by joneves-         ###   ########.fr       */
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
# include <limits.h>

// typedef struct s_table
// {
// 	int		realtime;
// 	t_philo	**philos;
// }	t_table;

// typedef struct s_philo
// {
// 	unsigned int	time_die;
// 	unsigned int	time_eat;
// 	unsigned int	time_sleep;
// 	t_table			*table;
// }	t_philo;

/* ft_parser.c */

int		ft_parser(int argc, char **argv);

/* ft_philo_utils.c */

size_t			ft_get_time(void);
long			ft_atol(const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);

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