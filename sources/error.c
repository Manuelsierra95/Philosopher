/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:35:29 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:43:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	errormsg(int flag)
{
	if (flag == 1)
	{
		printf("----> Error al crear el hilo <----\n");
	}
	else if (flag == 2)
	{
		printf("----> Error al crear el mutex <----\n");
	}
}
