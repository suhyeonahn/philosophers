/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:08:27 by suahn             #+#    #+#             */
/*   Updated: 2021/12/27 18:13:46 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	white(void)
{
	printf("\033[1;37m");
}

void	red(void)
{
	printf("\033[1;31m");
}

void	yellow(void)
{
	printf("\033[1;33m");
}

void	blue(void)
{
	printf("\033[1;34m");
}

void	purple(void)
{
	printf("\033[1;36m");
}
