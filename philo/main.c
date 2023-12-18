/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 04:12:53 by gotunc            #+#    #+#             */
/*   Updated: 2023/12/18 10:04:46 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				check_dead;
	int				i;

	i = 0;
	check_dead = 0;
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	while (i < ft_atol(av[1]))
		philo[i++].args = malloc(sizeof(int) * 5);
	forks = malloc(sizeof(pthread_mutex_t));
	if (!philo || !forks)
		return (1);
	if (argumentinit(philo, ac, av, &check_dead))
		return (1);
	initmutex(philo, forks);
	initthread(philo);
	freemutex(philo, forks);
	return (0);
}
