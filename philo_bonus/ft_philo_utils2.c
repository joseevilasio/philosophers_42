/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:16:00 by joneves-          #+#    #+#             */
/*   Updated: 2025/01/13 19:59:06 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	ft_digitlen(int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_digitlen(n);
	str = (char *) malloc(size * sizeof(char) + 1);
	if (str)
	{
		if (n < 0)
		{
			n = -1 * n;
			str[0] = '-';
		}
		str[size] = '\0';
		while (size-- > 0 && n > 9)
		{
			str[size] = n % 10 + '0';
			n = n / 10;
		}
		str[size] = n + '0';
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size;
	unsigned int	size_s1;
	unsigned int	size_s2;

	if (s1 && s2)
	{
		size_s1 = ft_strlen((char *) s1);
		size_s2 = ft_strlen((char *) s2);
		size = size_s1 + size_s2;
		str = (char *) malloc(size * sizeof(char) + 1);
		if (str)
		{
			ft_strlcpy(str, (char *)s1, size_s1 + 1);
			ft_strlcpy(str + size_s1, (char *)s2, size_s2 + 1);
			return (str);
		}
	}
	return (NULL);
}
