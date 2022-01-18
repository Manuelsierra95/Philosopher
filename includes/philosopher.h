#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/*
Required
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_state
{
    int t_die;
    int t_eat;
    int t_sleep;
    int m_eat;
}	t_state;
typedef struct s_philo
{
	int     count;
    int     time;
	t_state state;
}	t_philo;
typedef struct s_table
{
    struct s_table *left;
    struct s_table *rigth;
    struct t_philo *philo;
}	t_table;
int	ft_atoi(const char *str);


void    ft_parse(int argc, char **argv, t_philo *philo);
#endif
