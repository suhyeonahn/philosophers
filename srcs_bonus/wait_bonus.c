#include "../includes_bonus/philo_bonus.h"

void    wait_for_meal(t_rules *rules)
{
    int i;

    i = -1;
    while((++i < rules->num_philos))
        sem_wait(rules->ate_signal);
    i = -1;
    sem_post(rules->died_signal);
}

void    *wait_for_die(void  *r)
{
    t_rules *rules;
    int i;
 
    rules = (t_rules *)r;
    sem_wait(rules->died_signal);
    i = -1;
    while((++i < rules->num_philos))
        sem_post(rules->stop_philo_process);
    usleep(100);
    sem_post(rules->check_meal);
    sem_post(rules->check_stop);
    pthread_exit(NULL);
}

void    wait_for_stop(t_rules    *rules)
{
    pthread_t   die;
    pid_t   meal;

    meal = fork();
    if (meal < 0)
        exit(0);
    else if (meal == 0)
        wait_for_meal(rules);
    pthread_create(&die, &rules->attr, wait_for_die, (void *)rules);
    pthread_join(die, NULL);
    kill(meal, 15);
}