/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:38:51 by ldick             #+#    #+#             */
/*   Updated: 2024/05/14 12:56:02 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
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
}