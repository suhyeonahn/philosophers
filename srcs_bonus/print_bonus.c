#include "../includes_bonus/philo_bonus.h"

long long	timestamp(struct timeval    t)
{
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int    print_status(t_rules *rules, int id, char *str, int status)
{
	sem_wait(rules->check_stop);
	if (rules->philo[id].died)
	{
		sem_post(rules->check_stop);
		return (0);
	}
	sem_wait(rules->print_status);
	if (status == 11)
		white();
	else if (status == 33)
	{
		purple();
		rules->philo[id].eat_count++;
		if (rules->philo[id].eat_count == rules->num_meals)
		{
			sem_post(rules->ate_signal);
			usleep(500);
		}
	}
	else if (status == 77)
		blue();
	else if (status == 99)
		yellow();
	else if (status == 444)
	{
		red();
	}
	gettimeofday(&rules->now, NULL);
	printf("%lli ms ", timestamp(rules->now) - timestamp(rules->beginning));
	printf("%i ", id + 1);
	printf("%s\n", str);
	reset();
	sem_post(rules->print_status);
	if (status != 444)
	{
		sem_post(rules->check_stop);
	}
	return (1);
}