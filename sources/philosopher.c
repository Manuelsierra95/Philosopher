#include"../includes/philosopher.h"

/*
    
*/

int main(int argc, char **argv)
{
    t_philo philo;

    ft_parse(argc, argv, &philo);
    ft_pthreadcreate();

    return (0);
}