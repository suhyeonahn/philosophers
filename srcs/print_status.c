/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:14:09 by suahn             #+#    #+#             */
/*   Updated: 2021/12/27 18:19:08 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_fork(t_philo *p, int id, char *str, int fork)
{
	white();
	printf("%lli ms ", timestamp(p->rules->now)
		- timestamp(p->rules->beginning));
	printf("%i ", id + 1);
	printf("%s", str);
	printf("%d fork\n", fork);
	reset();
}

void	print_eat(t_philo *p, int id, char *str)
{
	int	i;
	int	ate;

	purple();
	printf("%lli ms ", timestamp(p->rules->now)
		- timestamp(p->rules->beginning));
	printf("%i ", id + 1);
	printf("%s", str);
	p->eat_count++;
	gettimeofday(&p->last_meal, NULL);
	i = 0;
	ate = 0;
	while (p->rules->num_meals && i < p->rules->num_philos)
	{
		if (p->rules->philo[i].eat_count < p->rules->num_meals)
			break ;
		ate++;
		i++;
	}
	if (p->rules->num_meals && ate == p->rules->num_philos)
	{
		p->rules->all_ate = 1;
	}
	reset();
}

void	print_sleep(t_philo *p, int id, char *str)
{
	blue();
	printf("%lli ms ", timestamp(p->rules->now)
		- timestamp(p->rules->beginning));
	printf("%i ", id + 1);
	printf("%s", str);
	reset();
}

void	print_think(t_philo *p, int id, char *str)
{
	yellow();
	printf("%lli ms ", timestamp(p->rules->now)
		- timestamp(p->rules->beginning));
	printf("%i ", id + 1);
	printf("%s", str);
	reset();
}

void	print_die(t_philo *p, int id, char *str)
{
	red();
	printf("%lli ms ", timestamp(p->rules->now)
		- timestamp(p->rules->beginning));
	printf("%i ", id + 1);
	printf("%s", str);
	p->rules->died = 1;
	reset();
}
