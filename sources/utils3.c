/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:06:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/24 17:54:25 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	t_sleep(t_philo *philo, size_t t_sleep)
{
	size_t	time;
	int		tok;

	time = gettime();
	tok = 0;
	philo->time += t_sleep;
	if (philo->state->is_dead == 0)
	{
		while (1)
		{
			if (gettime() - time >= t_sleep)
				break ;
			usleep(100);
		}
	}
}

void	print_msg(t_philo *philo, int flag, int id)
{
	size_t	time;

	time = gettime() - philo->state->t_init;
	pthread_mutex_lock(&philo->state->print);
	if (philo->state->is_dead == 0)
	{
		if (flag == 1)
			printf(BLUE "[%zu ms]\tPhilo %d is taking a fork\n" RESET, time, id);
		if (flag == 2)
			printf(CYAN "[%zu ms]\tPhilo %d left the fork\n" RESET, time, id);
		if (flag == 3)
			printf(GREEN "[%zu ms]\tPhilo %d is Eating\n" RESET, time, id);
		if (flag == 4)
			printf(PINK "[%zu ms]\tPhilo %d is Sleeping\n" RESET, time, id);
		if (flag == 5)
			printf(YELLOW "[%zu ms]\tPhilo %d is Thinking\n" RESET, time, id);
		if (flag == 6)
			printf(RED "[%zu ms]\tPhilo %d is Dead\n" RESET, time, id);		
		if (flag == 7)
			printf("[%zu ms]\tPhilo %d finish eating\n", time, id);
	}
	pthread_mutex_unlock(&philo->state->print);
}