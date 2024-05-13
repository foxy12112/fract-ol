/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:26:30 by ldick             #+#    #+#             */
/*   Updated: 2024/05/13 20:04:44 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void data_init(t_fractal *f)
{
	f->escape_val = 4;
}

void event_init(t_fractal *f)
{
	mlx_key_hook(f->mlx_window, MLX_KEY_F10, f);
	// mlx_key_hook(f->mlx_window, ButtonPress, f);
	// mlx_key_hook(f->mlx_window, DestroyNotify, f);
}

void	init_fractal(t_fractal *f, t_img img)
{
	f->mlx_window = mlx_init(WIDTH, HIGHT, "fractol", true);
	if (f->mlx_window == NULL)
		return ;
	img.img_ptr = mlx_new_image(f->mlx_window, WIDTH, HIGHT);
	if (img.img_ptr == NULL)
		return ;
	// event_init(f);
	data_init(f);
}