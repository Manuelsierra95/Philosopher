/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/19 13:46:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

thinking()
{
	write(1, "Thinking\n", 7);
	
}

eating()
{
	write(1, "Eating\n", 7);
	
}

sleeping()
{
	write(1, "Sleeping\n", 7);
	
}

died()
{
	write(1, "Died\n", 7);
	
}

void	*philostate()
{
	int	eating;
	int	sleeping;
	int	thinking;
	int	died;

	thinking();
	if()
	eating();
	sleeping();
	died();
}
