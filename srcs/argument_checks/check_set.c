/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:31 by ldick             #+#    #+#             */
/*   Updated: 2024/05/02 12:46:00 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// returns 3 for mandelbrot set or 5 for julia set

int	mandelbrot_and_julia_check(char *set, int len)
{
	if (set[0] == 'M' || set[0] == '-')
	{
		if (ft_strncmp(set, "-m", len) == 0)
			return (3);
		if (ft_strncmp(set, "Mandelbrot", len) == 0)
			return (3);
	}
	if (set[0] == 'J' || set[0] == 'j')
	{
		if (ft_strncmp(set, "-j", len) == 0)
			return (5);
		if (ft_strncmp(set, "Julia", len) == 0)
			return (5);
	}
	return (1);
}

int	check_the_set(char *set)
{
	int		len;

	len = ft_strlen(set);
	if (len != 2 && len != 5 && len != 10)
		return (1);
	
	return (0);
}

int main(int argc, char *argv[])
{
	// mandelbrot_checks(argv[1], 10);
	// check_the_set(argv[1]);
	//
	return 0;
}
