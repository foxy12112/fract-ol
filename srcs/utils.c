/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:44:11 by ldick             #+#    #+#             */
/*   Updated: 2024/05/17 16:56:11 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double unscaled, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * unscaled - 0) / (old_max - 0) + new_min);
}

t_comp	sum_complex(t_comp z1, t_comp z2)
{
	t_comp	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_comp	square_complex(t_comp z)
{
	t_comp	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	info_message(char **argv)
{
	ft_printf("Usage: %s [OPTIONS]...\n", argv[0]);
	ft_printf("\nOptions:\n");
	ft_printf("  -j,   Generate Julia fractal.\n");
	ft_printf("  you can specify the julia set using 2 more arguments,");
	ft_printf("  only works for julia\n\n example: ./fractol -j 0.159 -0.654");
	ft_printf("  -m,   Generate Mandelbrot fractal.\n");
	ft_printf("  -b,   Generate an upside down burning ship fractal.\n\n");
	exit(EXIT_FAILURE);
}

void	z_and_y_init(t_comp *z)
{
	z->y = 0.0;
	z->x = 0.0;
}
