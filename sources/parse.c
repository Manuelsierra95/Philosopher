/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:37 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/26 19:27:51 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	getvalues(int argc, char **argv, t_state *state)
{
	state->need_clean = 0;
	state->is_dead = 0;
	state->numph = atoi(argv[1]);
	state->t_die = atoi(argv[2]);
	state->t_eat = atoi(argv[3]);
	state->t_sleep = atoi(argv[4]);
	state->t_init = (int)gettime();
	if (argc == 6)
	{
		if (argv[5] <= 0)
		{
			errormsg(3);
			exit(0);
		}
		state->m_eat = atoi(argv[5]);
	}
	else
		state->m_eat = -1;
	state->all_eat = state->numph * state->m_eat;
}
