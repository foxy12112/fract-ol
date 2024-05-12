/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:26:30 by ldick             #+#    #+#             */
/*   Updated: 2024/05/12 15:12:10 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void data_init(t_fractal *f)
{
	f->escape_val = 4;
}

void event_init(t_fractal *f)
{
	mlx_key_hook()
}

void	init_fractal(t_fractal *f)
{
	f->mlx_window = mlx_init(WIDTH, HIGHT, "fractol", true);
	if (f->mlx_window == NULL)
		return ;
	f->img.img_ptr = mlx_new_image(f->mlx_window, WIDTH, HIGHT);
	if (f->img.img_ptr == NULL)
		return ;
	data_init(f);
}