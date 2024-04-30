/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:31 by ldick             #+#    #+#             */
/*   Updated: 2024/04/30 20:33:25 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// returns 3 for mandelbrot set or 5 for julia set

int	mandelbrot_and_julia_check(char *set, int len)
{
	if (set[0] == 'M' || set[0] == 'm')
	{
		if (len == 1 && set[0] == 'm')
			return (3);
		if (len == 10 && ft_strncmp(set, "Mandelbrot", 10) == 0)
			return (3);
	}
	if (set[0] == 'J' || set[0] == 'j')
	{
		if (len == 1 && set[0] == 'j')
			return (5);
		if (len == 5 && ft_strncmp(set, "Julia", 5) == 0)
			return (5);
	}
	return (1);
}

int	check_the_set(char *set)
{
	char	*mandelbrot;
	int		len;

	len = ft_strlen(set);
	if (len != 1 && len != 5 && len != 10)
		return (1);
	
	return (0);
}

int main(int argc, char *argv[])
{
	// mandelbrot_checks(argv[1], 10);
	// check_the_set(argv[1]);
	return 0;
}
