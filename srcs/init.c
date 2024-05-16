/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:26:30 by ldick             #+#    #+#             */
/*   Updated: 2024/05/16 13:45:06 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void data_init(t_fractal *f)
{
	f->escape_val = 4;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1;
	f->max_iterations = DEFAULT_ITERATIONS;
}

void	fancy_name_maker(t_fractal *f)
{
	if (!(ft_strncmp(f->name, "-m", 2)))
		f->name = "Mandelbrot";
	else if (!(ft_strncmp(f->name, "-j", 2)))
		f->name = "Julia";
}

void	init_fractal(t_fractal *f)
{
	f->mlx_window = mlx_init(WIDTH, HIGHT, f->name, true);
	if (f->mlx_window == NULL)
		return ;
	f->img.img_ptr = mlx_new_image(f->mlx_window, WIDTH, HIGHT);
	if (f->img.img_ptr == NULL)
		return ;
	mlx_image_to_window(f->mlx_window, f->img.img_ptr, 0, 0);
	data_init(f);
}