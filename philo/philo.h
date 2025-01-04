/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:51 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/04 18:00:48 by joneves-         ###   ########.fr       */
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

# define MSG_GET_FORK "\033[1m\033[33m%lu %d has taken a fork\033[0m\n"
# define MSG_EAT "\033[1m\033[35m%lu %d is eating\033[0m\n"
# define MSG_SLEEP "\033[1m\033[34m%lu %d is sleeping\033[0m\n"
# define MSG_THINK "\033[1m\033[32m%lu %d is thinking\033[0m\n"
# define MSG_DEAD "\033[1m\033[31m%lu %d died\033[0m\n"

typedef struct s_philo t_philo;

typedef struct s_table
{
	//int		realtime;
	t_philo	**philos;
}	t_table;

typedef struct s_philo
{
	int		id;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		meal_goal;
	int		meals;
	size_t	last_meal;
	//size_t	start_time;
	t_table	*table;
}	t_philo;

/* ft_parser.c */

int		ft_parser(int argc, char **argv);

/* ft_philo_utils.c */

size_t	ft_get_time(void);
size_t	ft_elapsed_time(size_t start_time);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/* ft_actions.c */

void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_dead(t_philo *philo);
void	ft_get_fork(t_philo *philo);

/* ft_init.c */

t_philo	**ft_init_philos(int argc, char **argv);
t_table	*ft_init_table(t_philo **philos);

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