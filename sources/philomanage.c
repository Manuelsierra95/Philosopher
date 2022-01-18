#include"../includes/philosopher.h"

void	philostate()
{
	
}

void	ft_pthreadcreate(t_philo *philo)
{
	pthread_t	*pthread;
	int			i;

	i = 0;
	while(i < philo->count)
	{
		if(0 != pthread_create(pthread[i], NULL, &philostate, &philo[i]))
		{

		}
		i++;
	}
}