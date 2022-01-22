/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:37 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/22 15:10:08 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

long	get_time(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

int	getNumOfPhilo(char *argv)
{
	return (ft_atoi(argv));
}

void    getvalues(int argc, char **argv, t_state *state)
{
	state->numphilo = getNumOfPhilo(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		state->m_eat = ft_atoi(argv[5]);	
	}
}
