/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:01:33 by suahn             #+#    #+#             */
/*   Updated: 2021/12/27 18:08:08 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_args(int argc, char **argv, t_rules *rules)
{
	if (!((argc == 5) || (argc == 6)))
		return (-1);
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]) * 1000;
	rules->time_to_eat = ft_atoi(argv[3]) * 1000;
	rules->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (rules->num_philos < 1 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0)
		return (-1);
	if (argc == 6)
	{
		rules->num_meals = ft_atoi(argv[5]);
		if (rules->num_meals <= 0)
			return (-1);
	}
	else
		rules->num_meals = 0;
	return (0);
}
