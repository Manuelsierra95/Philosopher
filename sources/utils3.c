/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:06:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/03 15:54:36 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	t_sleep(t_philo *philo, int t_sleep)
{
	int	time;

	time = gettime();
	philo->time += t_sleep;
	while (1)
	{
		if (gettime() - time >= t_sleep)
			break ;
		usleep(100);
	}
}

void	add_timer(t_philo *philo, int time)
{
	pthread_mutex_lock(&philo->state->mutex[philo->id]);
	philo->time += time;
	pthread_mutex_unlock(&philo->state->mutex[philo->id]);
}

void	print_msg(t_philo *philo, int flag, int id)
{
	int	time;

	time = gettime() - philo->state->t_init;
	pthread_mutex_lock(&philo->state->print);
	if (philo->state->is_dead == 0 || flag == 6)
	{
		if (flag == 1)
			printf(BLUE "[%d ms]\tPhilo %d is taking a fork\n" RESET, time, id);
		if (flag == 2)
			printf(CYAN "[%d ms]\tPhilo %d left the fork\n" RESET, time, id);
		if (flag == 3)
			printf(GREEN "[%d ms]\tPhilo %d is Eating\n" RESET, time, id);
		if (flag == 4)
			printf(PINK "[%d ms]\tPhilo %d is Sleeping\n" RESET, time, id);
		if (flag == 5)
			printf(YELLOW "[%d ms]\tPhilo %d is Thinking\n" RESET, time, id);
		if (flag == 6)
			printf(RED "[%d ms]\tPhilo %d is Dead\n" RESET, time, id);
		if (flag == 7)
			printf("[%d ms]\tPhilo %d finish eating\n", time, id);
	}
	pthread_mutex_unlock(&philo->state->print);
}
