/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:51:03 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:48:52 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	lock_mutex(pthread_mutex_t *mutex, t_state *state, int i)
{
	pthread_mutex_lock(mutex);
	// printf("Valor de i: %d\n", i);
	// state->fork[i] = 1;
}

void	unlock_mutex(pthread_mutex_t *mutex, t_state *state, int i)
{
	// state->fork[i] = 0;
	pthread_mutex_unlock(mutex);
}

void	manage_fork(t_philo *philo, t_state *table)
{
	int	total;
	int	m1;
	int	m2;

	m1 = minthread(philo->id, (philo->id + 1)%philo->state->numphilo); //izq
	m2 = maxthread(philo->id, (philo->id + 1)%philo->state->numphilo); //der
	
	
	//0 no se necesita bloqueo, 1 o -1 hay un tenedor bloqueado
	//y necesitamos gestionar la fila
	//1 = derecha | -1 = izquierda
	total = table->fork[m1] - table->fork[m2];
	if(total == 0)
	{
		lock_mutex(&table->mutex[m1], &table[m1], m1);
		lock_mutex(&table->mutex[m2], &table[m2], m2);
	}
	else if (total == 1)
	{
		lock_mutex(&table->mutex[m1], &table[m1], m1);
		lock_mutex(&table->mutex[m2], &table[m2], m2);
	}
	else if (total == -1)
	{
		lock_mutex(&table->mutex[m2], &table[m2], m2);
		lock_mutex(&table->mutex[m1], &table[m1], m1);
	}
	unlock_mutex(&table->mutex[m1], &table[m1], m1);
	unlock_mutex(&table->mutex[m2], &table[m2], m2);
}
