/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:49:02 by mac               #+#    #+#             */
/*   Updated: 2022/03/08 18:32:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	m_init(t_philo *philo, pthread_mutex_t *forks, int n_p)
{
	int i = 0;
	
	while(i < n_p)
	{
		pthread_mutex_init(&forks[i],NULL);
		// philo[i].next_fork = &forks[(i + 1) % n_p];
		i++;
	}

	i = 0;
	while(i < n_p)
	{
		pthread_mutex_init(&philo->print,NULL);
		pthread_mutex_init(&philo->die,NULL);
		philo[i].fork = &forks[i];
		philo[i].next_fork = &forks[(i + 1) % n_p];
		i++;
	}
}
void	args_init(t_philo *philo, int ac, char **av)
{
	int	n;
	int	i;
	i = 0;
	n = ft_atoi(av[1]);
	while(i < n)
	{
		philo[i].n_p = n;
		philo[i].id = i + 1;
		philo[i].eat = ft_atoi(av[3]);
		if(ac == 6)
			philo[i].meals = ft_atoi(av[5]);
		else
			philo[i].meals = -1;
		philo[i].sleep = ft_atoi(av[4]);
		philo[i].time_to_die = ft_atoi(av[2]);
		i++;
	}
}

void	create_threads(t_philo *philo, int nf)
{
	int	i;

	i = 0;
	while(i < nf)
	{
		pthread_create(&philo[i].philo, NULL, &routine, (void *)&philo[i]);
		usleep(100);
		i++;
	}
}

long	time_now(void)
{
	struct timeval tv;

	gettimeofday(&tv,NULL);
	return ((tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0));
}

void	printing(t_philo *philo, char *msg, long time)
{
	pthread_mutex_lock(&philo->print);
	printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->print);
}

