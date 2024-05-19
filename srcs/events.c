/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:17:43 by ldick             #+#    #+#             */
/*   Updated: 2024/05/19 06:06:06 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_key_handler(mlx_key_data_t mkd, void *data)
{
	t_fractal	*f;

	f = (t_fractal *)data;
	if (mkd.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(f->mlx_window);
		exit(EXIT_SUCCESS);
	}
	if (mkd.key == MLX_KEY_LEFT)
		f->shift_x -= (0.25 * f->zoom);
	if (mkd.key == MLX_KEY_RIGHT)
		f->shift_x += (0.25 * f->zoom);
	if (mkd.key == MLX_KEY_DOWN)
		f->shift_y -= (0.25 * f->zoom);
	if (mkd.key == MLX_KEY_UP)
		f->shift_y += (0.25 * f->zoom);
	if (mkd.key == MLX_KEY_KP_ADD)
		f->max_iterations += 10;
	if (mkd.key == MLX_KEY_KP_SUBTRACT)
		f->max_iterations -= 10;
	if (mkd.key == MLX_KEY_KP_EQUAL)
		ft_printf("%d\n", f->max_iterations);
	fractal_render(f);
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	t_comp		*c;

	(void)xdelta;
	f = (t_fractal *)param;
	if (ydelta > 0)
		f->zoom *= 1.1;
	if (ydelta < 0)
		f->zoom *= 0.9;
	fractal_render(f);
}

void	leakcheck(void)
{
	system("leaks fractol");
}
