#include"../includes/philosopher.h"

void	ft_pthreadcreate(int argc, char **argv, t_philo *philo, int numphilo)
{
	pthread_t		*pthread;
	int				i;

	i = 0;
	while(i < numphilo)
	{
		if(0 != pthread_create(pthread[i], NULL, &philostate(), &philo[i]))
		{
			//error
		}
		getvalues(argc, argv, &philo[i]);
		pthread_mutex_init(philo[i].mutex, NULL);
		i++;
	}
}