/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:37:05 by gotunc            #+#    #+#             */
/*   Updated: 2023/11/29 01:45:26 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	TODO: GOWHİLE FONKSİYONU ASIL FONKSİYON OLACAK.
	TODO: BU FONKSİYON YEMEK YEME UYUMA VE DÜŞÜNME İŞLEVLERİNİ YAPACAK.
	TODO: MUTEXLER İLE İLGİLİ HENÜZ HİÇBİR ŞEY YAPILMADI.
	TODO: THREAD İLE İLGİLİ HENÜZ HİÇBİR ŞEY YAPILMADI.
*/

//void	gowhile(t_philo *data)
//{
//	int	eatnum;

//	eatnum = 0;
//	while (1)
//	{
//	}
//}

//void	initthread(t_philo *data)
//{
//	pthread_t	threads;
//}

void	initargs(t_philo *data, int argc, char **argv)
{
	long	i;

	i = 0;
	data->forknum = data->philonum / 2;
	while (i < ft_atol(argv[1]))
	{
		data[i].philonum = ft_atol(argv[1]);
		data[i].dietime = ft_atol(argv[2]);
		data[i].eattime = ft_atol(argv[3]);
		data[i].sleeptime = ft_atol(argv[4]);
		data[i].eatnum = 0;
		data[i].isdead = 0;
		if (argc == 6)
			data[i].catcheatnum = ft_atol(argv[5]);
		else
			data[i].catcheatnum = -1;
		i++;
	}
	data->totalphilo = i;
}

int	main(int argc, char **argv)
{
	t_philo	*data;

	if (argc == 5 || argc == 6)
	{
		if (errorcontrol(argv))
		{
			printf("Bad input! You must enter digit character");
			printf(" and this digit character is upper than zero!\n");
			return (-1);
		}
		data = malloc(sizeof(t_philo));
		if (!data)
			return (-1);
		initargs(data, argc, argv);
		//initthread(data);
		//gowhile(data);
	}
	else
		printf("Wrong Input! You must enter 4 or 5 arguments!\n");
	return (0);
}
