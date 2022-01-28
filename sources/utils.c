/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:44:47 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/28 18:11:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

int	minthread(int num1, int num2)
{
	if(num1 < num2)
		return (num1);
	else
		return (num2);
}

int	maxthread(int num1, int num2)
{
	if(num1 > num2)
		return (num1);
	else
		return (num2);
}

size_t	gettime(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	// printf("Sec: %ld\nUsec: %d\n", t_val.tv_sec * 1000, t_val.tv_usec / 1000);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

void	*check_dead(void *arg)
{
	int	i;
	t_state	*table;
	t_philo	*philo;

	// printf("all_eat: %d\tnumphilo: %d\n", state->all_eat, state->numphilo);
	philo = arg;
	table = philo->state;
	while (1)
	{
		i = 0;
		while(i < table->numphilo)
		{
			// printf("----------time: %zu\t gettime: %zu\n", philo[i].time, gettime());
			if (philo[i].time - gettime() < (unsigned long int) table->t_die)
			{
				printf("*******Javi tus muertos\n");
				table->is_dead = 1; // Para que paren de ejecutar los hilos sus funciones
				died(&philo[i]);
				cleanall(philo, table->numphilo, 0);
			}
			i++;	
		}
	}
	return (NULL);
}
