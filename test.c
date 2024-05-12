/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:26:49 by ldick             #+#    #+#             */
/*   Updated: 2024/05/12 15:02:30 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
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
	t_comp result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}


void handle_pixel(int x, int y, t_fractal *f)
{
	t_comp	z;
	t_comp	c;
	int		i;
	int		color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HIGHT);
	while (i < MAX_ITERATIONS)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_val)
		{
			color = map(i, BLACK, WHITE, 0, MAX_ITERATIONS);
			mlx_put_pixel(f->mlx_window, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->mlx_window, x, y, GOLD);
}

void fractal_render(t_fractal *f)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, f);
		}
	}
	mlx_image_to_window(f->mlx_window, f->img.img_ptr, 0, 0);
}

int	main(void)
{
	t_fractal f;

	f.escape_val = 4;
	f.mlx_window = mlx_init(WIDTH, HIGHT, "fractol", true);
	fractal_render(&f);
	mlx_loop(f.mlx_window);
}
