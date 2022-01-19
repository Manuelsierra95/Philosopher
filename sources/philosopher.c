/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/19 15:38:57 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
    
*/

int main(int argc, char **argv)
{
	t_philo			philo;
	int				numphilo;

	numphilo = getNumOfPhilo(argv[1]);
    ft_pthreadcreate(argc, **argv, &philo, numphilo);
	ft_managepthreads(numphilo, &philo);

    return (0);
}