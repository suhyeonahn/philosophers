/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:19:27 by suahn             #+#    #+#             */
/*   Updated: 2021/12/27 18:21:45 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	reset(void)
{
	printf("\033[0m");
}

long long	timestamp(struct timeval t)
{
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	print_status(t_philo *p, int id, char *str, int status)
{
	pthread_mutex_lock(&(p->rules->check_death));
	if (p->rules->died || p->rules->all_ate)
	{
		if (status)
			pthread_mutex_unlock(&(p->rules->check_death));
		return (0);
	}
	pthread_mutex_lock(&(p->rules->print_status));
	gettimeofday(&p->rules->now, NULL);
	if (status > 0)
		print_fork(p, id, str, status);
	else if (status == -33)
		print_eat(p, id, str);
	else if (status == -77)
		print_sleep(p, id, str);
	else if (status == -99)
		print_think(p, id, str);
	else if (status == -444)
		print_die(p, id, str);
	pthread_mutex_unlock(&(p->rules->check_death));
	pthread_mutex_unlock(&(p->rules->print_status));
	return (1);
}
