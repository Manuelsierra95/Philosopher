/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:50:08 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:39:31 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_is_space(char c);

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned int	c;

	sign = 1;
	i = 0;
	c = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (c * 10) + (str[i] - '0');
		if (c > 2147483647 && sign == 1)
			return (-1);
		if (c > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (c * sign);
}

static int	ft_is_space(char c)
{
	if (c == ' ' || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}
