#include "../includes_bonus/philo_bonus.h"

void    init_philos(t_rules    *rules)
{
    int i;

    i = 0;
    while (i < rules->num_philos)
    {
        rules->philo[i].id = i;
        rules->philo[i].died = 0;
        rules->philo[i].eat_count = 0;
        rules->philo[i].rules = rules;
        gettimeofday(&rules->philo[i].last_meal, NULL); 
        i++;
    }
}

int init_semaphore(t_rules  *rules)
{
    sem_unlink("fork");
    sem_unlink("print_status");
    sem_unlink("ate_siganl");
    sem_unlink("died_signal");
    sem_unlink("check_stop");
    sem_unlink("check_meal");
    sem_unlink("check_death");
    sem_unlink("stop_philo_process");
    rules->stop_philo_process = sem_open("stop_philo_process", O_CREAT | O_EXCL, 0777, 0);
    rules->check_stop = sem_open("check_stop", O_CREAT | O_EXCL, 0777, 1);
    rules->check_meal = sem_open("check_meal", O_CREAT | O_EXCL, 0777, 1);
    rules->check_death = sem_open("check_death", O_CREAT | O_EXCL, 0777, 1);
    rules->fork = sem_open("fork", O_CREAT | O_EXCL, 0777, rules->num_philos);
    rules->ate_signal = sem_open("ate_siganl", O_CREAT | O_EXCL, 0777, 0);
    rules->died_signal = sem_open("died_signal", O_CREAT | O_EXCL, 0777, 0);
    rules->print_status = sem_open("print_status", O_CREAT | O_EXCL, 0777, 1);
    if (rules->fork == SEM_FAILED || rules->print_status == SEM_FAILED || rules->ate_signal == SEM_FAILED
        || rules->died_signal == SEM_FAILED || rules->check_stop == SEM_FAILED
        || rules->check_meal == SEM_FAILED || rules->stop_philo_process == SEM_FAILED
        || rules->check_death == SEM_FAILED)
    {
        write(1, "sem_open error\n", 15);
        return (-1);
    }
    return (0);
}

int    init_rules(t_rules  *rules)
{
    gettimeofday(&rules->beginning, NULL);
    if (init_semaphore(rules) < 0)
        return (-1);
    init_philos(rules);
    if (pthread_attr_init(&rules->attr) != 0)
        return (-1);
    pthread_attr_setdetachstate(&rules->attr, PTHREAD_CREATE_JOINABLE);
    return (0);
}