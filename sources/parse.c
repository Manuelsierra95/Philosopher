#include"../includes/philosopher.h"

long	get_time(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

void    ft_parse(int argc, char **argv, t_philo *philo)
{

    philo->count = ft_atoi(argv[1]);
    philo->state.t_die = ft_atoi(argv[2]);
    philo->state.t_eat = ft_atoi(argv[3]);
    philo->state.t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    philo->state.m_eat = ft_atoi(argv[5]);
    philo->time = get_time();
}
