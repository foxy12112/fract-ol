/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:38:51 by ldick             #+#    #+#             */
/*   Updated: 2024/05/16 15:56:52 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void Mandelbrot(int x, int y, t_fractal *f)
{
	t_comp	z;
	t_comp	c;
	int		i;
	int		color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
	c.y = (map(y, +2, -2, 0, HIGHT) * f->zoom) + f->shift_y;
	
	
	while (i < f->max_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_val)
		{
			color = map(i, BLACK, WHITE, 0, f->max_iterations);
			mlx_put_pixel(f->img.img_ptr, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img.img_ptr, x, y, GOLD);
}
//renders the fractal with either Jlia set or mandelbrot set
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
			if (!ft_strcmp(f->name, "Mandelbrot"))
				Mandelbrot(x, y, f);
			else if (!ft_strcmp(f->name, "Julia"))
				Julia(x, y, f);
		}
	}
}

void triangle(int x, int y, t_fractal *f)
{
	t_comp	z;
	t_comp	c;
	int		i;
	int		color;
	
	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
	z.y = (map(y, +2, -2, 0, HIGHT) * f->zoom) + f->shift_y;
	
	
}

void Julia(int x, int y, t_fractal *f)
{
	t_comp	z;
	t_comp	c;
	int		i;
	int		color;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
	z.y = (map(y, +2, -2, 0, HIGHT) * f->zoom) + f->shift_y;

	c.x = f->julia_x;
	c.y = f->julia_y;

	while (i < f->max_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_val)
		{
			color = map(i, BLACK, WHITE, 0, f->max_iterations);
			mlx_put_pixel(f->img.img_ptr, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img.img_ptr, x, y, GOLD);
}