/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:51:03 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/03 15:54:21 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	onephilo(t_philo *philo)
{
	t_sleep(philo, philo->state->t_die);
	died(philo);
	cleanall(philo, 0);
}

void	lock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id)
{
	pthread_mutex_lock(mutex);
	philo->state->fork[i] = 1;
	print_msg(philo, 1, id);
	if (philo->state->numph == 1)
		onephilo(philo);
}

void	unlock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id)
{
	philo->state->fork[i] = 0;
	pthread_mutex_unlock(mutex);
	print_msg(philo, 2, id);
}

void	manage_fork(t_philo *philo, t_state *table)
{
	int	m1;
	int	m2;

	m1 = minthread(philo->id, (philo->id + 1) % philo->state->numph);
	m2 = maxthread(philo->id, (philo->id + 1) % philo->state->numph);
	lock_mutex(&table->mutex[m1], philo, m1, philo->id);
	lock_mutex(&table->mutex[m2], philo, m2, philo->id);
	print_msg(philo, 3, philo->id);
	t_sleep(philo, table->t_eat);
	table->l_eat = gettime();
	philo->n_food = 0;
	unlock_mutex(&table->mutex[philo->id], philo, m1, philo->id);
	unlock_mutex(&table->mutex[(philo->id + 1) % philo->state->numph],
		philo, m2, philo->id);
}
