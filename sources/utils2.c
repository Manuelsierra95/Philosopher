/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:51:03 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/07 17:47:14 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	lock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id)
{
	int	time;

	time = philo->state->pt;
	pthread_mutex_lock(mutex);
	printf(BLUE "[%d]\tPhilo %d is taking a fork\n" RESET, time, id);
	philo->state->fork[i] = 1;
}

void	unlock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id)
{
	int	time;

	time = philo->state->pt;
	philo->state->fork[i] = 0;
	pthread_mutex_unlock(mutex);
	printf(CYAN "[%d]\tPhilo %d left the fork\n" RESET, time, id);
}

//0 no se necesita bloqueo, 1 o -1 hay que coger un tenedor
//1 = derecha | -1 = izquierda
void	manage_fork(t_philo *philo, t_state *table)
{
	int	total;
	int	m1;
	int	m2;

	m1 = minthread(philo->id, (philo->id + 1) % philo->state->numph);
	m2 = maxthread(philo->id, (philo->id + 1) % philo->state->numph);
	total = table->fork[m1] - table->fork[m2];
	if (total == 0)
	{
		lock_mutex(&table->mutex[m1], philo, m1, philo->id);
		lock_mutex(&table->mutex[m2], philo, m2, philo->id);
	}
	else if (total == 1)
	{
		lock_mutex(&table->mutex[m1], philo, m1, philo->id);
		lock_mutex(&table->mutex[m2], philo, m2, philo->id);
	}
	else if (total == -1)
	{
		lock_mutex(&table->mutex[m2], philo, m2, philo->id);
		lock_mutex(&table->mutex[m1], philo, m1, philo->id);
	}
	printf(GREEN "[%d]\tPhilo %d is Eating\n" RESET, philo->state->pt, philo->id);
	unlock_mutex(&table->mutex[m1], philo, m1, philo->id);
	unlock_mutex(&table->mutex[m2], philo, m2, philo->id);
}

void	sleeptime(size_t time, t_philo *philo)
{
	size_t	t;

	t = gettime();
	while (gettime() - t <= time)
	{
		philo->state->pt += 100;
		usleep(100);
	}
}
