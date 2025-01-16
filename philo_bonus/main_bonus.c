/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:06:23 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/15 20:50:27 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (ft_parser(argc, argv) != 0)
		return (2);
	table = ft_init(argc, argv);
	if (!table)
		return (1);
	ft_start_dinner(table);
	ft_free(table);
	return (0);
}
