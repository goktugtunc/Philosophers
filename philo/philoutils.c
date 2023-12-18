/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 04:12:35 by gotunc            #+#    #+#             */
/*   Updated: 2023/12/18 10:16:27 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printphilo(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->checkdead)
	{
		printf("%ld %d %s\n", (gettime() - philo->time),
			philo->id, status);
		if (!ft_strcmp(status, "is died"))
			*philo->checkdead = 1;
	}
	pthread_mutex_unlock(philo->death);
}

int	waitfunc(time_t waitime_t)
{
	time_t	time;

	time = gettime();
	while (gettime() - time < waitime_t)
	{
		usleep(100);
	}
	return (0);
}

time_t	gettime(void)
{
	struct timeval	tp;
	time_t			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}
