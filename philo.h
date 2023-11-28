/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:33:15 by gotunc            #+#    #+#             */
/*   Updated: 2023/11/29 00:43:35 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	totalphilo;
	int	philonum;
	int	forknum;
	int	eattime;
	int	eatnum;
	int	dietime;
	int	sleeptime;
	int	catcheatnum;
	int	isdead;
}	t_philo;

long	ft_atol(const char *str);
int		errorcontrol(char **argv);

#endif