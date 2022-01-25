/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:44:47 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/25 16:21:09 by msierra-         ###   ########.fr       */
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
