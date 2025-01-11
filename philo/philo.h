/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:51 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/11 21:21:52 by joneves-         ###   ########.fr       */
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
# include <stdbool.h>

/* Colors and Style*/

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

# define MSG_TAKE_FORK "\033[1m\033[33m%lu %d has taken a fork\033[0m\n"
# define MSG_EAT "\033[1m\033[35m%lu %d is eating\033[0m\n"
# define MSG_SLEEP "\033[1m\033[34m%lu %d is sleeping\033[0m\n"
# define MSG_THINK "\033[1m\033[32m%lu %d is thinking\033[0m\n"
# define MSG_DIE "\033[1m\033[31m%lu %d died\033[0m\n"

# define FIRST 1
# define SECOND 2

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				number_of_philos;
	int				meals_goal;
	int				meals_goal_each;
	bool			meals_goal_reached;
	bool			all_alive;
	size_t			start_time;
	pthread_mutex_t	mutex_alive;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	*mutex_fork;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				meals_to_eat;
	bool			reached;
	int				left_fork;
	int				right_fork;
	size_t			last_meal_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	mutex_time;
	t_table			*table;
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
void	ft_take_fork(t_philo *philo);
void	ft_think(t_philo *philo);

/* ft_actions.c */

void	ft_wait(t_philo *philo, size_t time);
void	ft_solo_dining(t_philo *philo);
int		ft_order_fork(t_philo *philo, int which);

/* ft_init.c */

t_table	*ft_init(int argc, char **argv);

/* ft_free.c */

void	ft_free(t_table *table);

/* ft_start.c */

int		ft_start_dinner(t_table *table, t_philo **philos);

/* ft_monitoring */

void	ft_monitoring(t_table *table);
bool	ft_check_everything(t_table *table);
bool	ft_alive_print_msg(t_philo *philo, const char *msg);

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