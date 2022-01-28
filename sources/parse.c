/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:37 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/28 18:20:13 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void    getvalues(int argc, char **argv, t_state *state)
{
	state->need_clean = 0;
	state->is_dead = 0;
	state->numphilo = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		state->m_eat = ft_atoi(argv[5]);
	}
	else
		state->m_eat = -1;
}
