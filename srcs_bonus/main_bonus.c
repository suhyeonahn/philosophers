#include "../includes_bonus/philo_bonus.h"

void    destroy(t_rules *rules)
{
    pthread_attr_destroy(&rules->attr);
    sem_close(rules->fork);
    sem_unlink("fork");
    sem_close(rules->print_status);
    sem_unlink("print_status");
    sem_close(rules->ate_signal);
    sem_unlink("ate_signal");
    sem_close(rules->died_signal);
    sem_unlink("died_signal");
    sem_close(rules->check_stop);
    sem_unlink("check_stop");
    sem_close(rules->check_meal);
    sem_unlink("check_meal");
    sem_close(rules->check_death);
    sem_unlink("check_death");
    sem_close(rules->stop_philo_process);
    sem_unlink("stop_philo_process");
    pthread_exit(NULL);
}

int eat(t_philo  *p)
{
    int ret;

    ret = 0;
    if (p->rules->num_philos == 1)
	{
        sem_wait(p->rules->fork);
        ret = print_status(p->rules, p->id, "has a fork", 11);
        sem_post(p->rules->fork);
		return (0);
	}
    sem_wait(p->rules->fork);
    sem_wait(p->rules->fork);
    ret = print_status(p->rules, p->id, "has a fork", 11);
    ret = print_status(p->rules, p->id, "has a fork", 11);
    sem_wait(p->rules->check_meal);
    ret = print_status(p->rules, p->id, "is eating", 33);
    sem_post(p->rules->check_meal);
    gettimeofday(&p->last_meal, NULL); 
    usleep(p->rules->time_to_eat);
    sem_post(p->rules->fork);
    sem_post(p->rules->fork);
    return (ret);
}

void    *philo_acts(void *philo)
{
    t_philo *p;

    p = (t_philo *)philo;
    while (1)
    {
        if (!eat(p))
            break;
        if (!print_status(p->rules, p->id, "is sleeping", 77))
            break;
        usleep(p->rules->time_to_sleep);
        if (!print_status(p->rules, p->id, "is thinking", 99))
            break;
    }
    pthread_exit(NULL);
}

void    philo_process(t_philo *p)
{
    if (pthread_create(&(p->t_id), &p->rules->attr, philo_acts, (void *)p) < 0)
        exit (0);
    if (pthread_create(&(p->stop_check_t_id), &p->rules->attr, stop_checker, (void *)p) < 0)
        exit (0);
    death_checker(p);
    pthread_join(p->stop_check_t_id, NULL);
    pthread_join(p->t_id, NULL);
    exit(0);
}

void    create_philo_processes(t_rules *rules)
{
    t_philo *philo;
    int i;

    philo = rules->philo;
    i = 0;
    while (i < rules->num_philos)
    {
        philo[i].p_id = fork();
        if (philo[i].p_id < 0)
            exit(0);
        else if (philo[i].p_id == 0)
            philo_process(&philo[i]);
        i++;
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    t_rules rules;
    int ret;

    ret = parse_args(argc, argv, &rules);
	if (ret < 0)
	{
		write(1, "Error: Wrong argument(s)\n", 25);
		exit (0);
	}
	ret = init_rules(&rules);
	if (ret < 0)
	{
		write(1, "Error: Initialization failed\n", 29);
		exit (0);
	}
    create_philo_processes(&rules);
    wait_for_stop(&rules);
    destroy(&rules);
}