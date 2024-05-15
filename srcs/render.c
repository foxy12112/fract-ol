/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:38:51 by ldick             #+#    #+#             */
/*   Updated: 2024/05/15 15:14:08 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void handle_pixel(int x, int y, t_fractal *f)
{
	t_comp	z;
	t_comp	c;
	int		i;
	int		color;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
	z.y = (map(y, +2, -2, 0, HIGHT) * f->zoom) + f->shift_y;
	
	julia(&z, &c, f);
	
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

void julia(t_comp *z, t_comp *c, t_fractal *f)
{
	if (!ft_strcmp(f->name, "Julia"))
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}