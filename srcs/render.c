/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:38:51 by ldick             #+#    #+#             */
/*   Updated: 2024/05/11 18:26:13 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
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
		if ((z.x * z.x) + (x.y * z.y) > f->escape_val)
		{
			color = map(i, BLACK, WHITE, 0, MAX_ITERATIONS);
			my_pixel_put();
			return ;
		}
	}
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
			handle_pixel(x, y, f)
		}
	}
}