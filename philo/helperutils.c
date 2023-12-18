/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 04:13:05 by gotunc            #+#    #+#             */
/*   Updated: 2023/12/18 10:11:40 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_atol(char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > 2147483648)
			return (-1);
	}
	if ((result * sign) == 2147483648)
		return (-1);
	return ((int)result * sign);
}

void	freemutex(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->args[PHILOCOUNT])
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philo[i].lasteatmutex);
		pthread_mutex_destroy(&philo[i].totaleatmutex);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	free(forks);
	free(philo);
}
