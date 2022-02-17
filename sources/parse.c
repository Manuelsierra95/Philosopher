/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:37 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/17 17:21:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	getvalues(int argc, char **argv, t_state *state)
{
	if (argv[1] < 0 || argv[2] < 0 || argv[3] < 0 || argv[4] < 0)
	{
		errormsg(3);
		exit(0);
	}
	state->need_clean = 0;
	state->is_dead = 0;
	state->numph = atoi(argv[1]);
	state->t_die = atoi(argv[2]);
	state->t_eat = atoi(argv[3]);
	state->t_sleep = atoi(argv[4]);
	state->t_init = gettime();
	if (argc == 6)
	{
		if (argv[5] < 0)
		{
			errormsg(3);
			exit(0);
		}
		state->m_eat = atoi(argv[5]);
	}
	else
		state->m_eat = -1;
}
