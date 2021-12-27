#include "../includes_bonus/philo_bonus.h"

void    death_checker(t_philo *p)
{
    while (1)
    {
        sem_wait(p->rules->check_meal);
        gettimeofday(&p->rules->now, NULL);
        if ((timestamp(p->rules->now) -
        timestamp(p->last_meal)) > (p->rules->time_to_die / 1000))
        {
            if (print_status(p->rules, p->id, "has died", 444))
            {
                sem_post(p->rules->died_signal);
                break;
            }
        }
        sem_post(p->rules->check_meal);
    }
}

void    *stop_checker(void *philo)
{
    t_philo *p;

    p = (t_philo *)philo;
    sem_wait(p->rules->stop_philo_process);
    sem_wait(p->rules->check_death);
    p->died = 1;
    sem_post(p->rules->check_death);
    pthread_exit(NULL);
}