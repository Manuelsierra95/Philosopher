/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:35:29 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/03 15:53:44 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	errormsg(int flag)
{
	if (flag == 1)
		printf("----> Error: thread <----\n");
	else if (flag == 2)
		printf("----> Error: mutex <----\n");
	else if (flag == 3)
		printf("----> Error: wrong arguments <----\n");
	else if (flag == 4)
		printf("----> Error: join <----\n");
	else if (flag == 5)
		printf("----> Error: Incorrect number of arguments <----\n");
	exit(0);
}

void	checkerror(int argc, char **argv)
{
	int	x;
	int	y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y])
		{
			if (argv[x][y] == '-' || argv[x][y] == '+')
			{
				y++;
				if (argv[x][y] == '-' || argv[x][y] == '+')
					errormsg(3);
			}
			if (!((argv[x][y] >= '0' && argv[x][y] <= '9') || (argv[x][y] == '-'
					|| argv[x][y] == '+')))
				errormsg(3);
			y++;
		}
		x++;
	}
}

void	errorcontrol(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		errormsg(5);
	else if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0
		|| atoi(argv[4]) <= 0)
		errormsg(3);
	else if (atoi(argv[1]) > 200)
		errormsg(3);
	else if (atoi(argv[2]) < 60 || atoi(argv[3]) < 60 || atoi(argv[4]) < 60)
		errormsg(3);
	checkerror(argc, argv);
}
