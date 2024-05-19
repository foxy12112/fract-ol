/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:26:30 by ldick             #+#    #+#             */
/*   Updated: 2024/05/19 06:08:35 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *f)
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
	else if (!(ft_strcmp(f->name, "-b")))
		f->name = "Burning_Ship";
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

void	julia_base_init(t_fractal *f)
{
	f->julia_x = -0.7269;
	f->julia_y = 0.1889;
}

int	mlx_argv_check(int argc, char **argv, t_fractal *f)
{
	if (argc == 1 || argc > 4 || argc == 3)
	{
		info_message();
		return (1);
	}
	if (!(ft_strcmp(argv[1], "-m") == 0 || ft_strcmp(argv[1], "-b") == 0
			|| ft_strcmp(argv[1], "-j") == 0))
	{
		info_message();
		return (1);
	}
	if (!ft_strcmp(argv[1], "-j") && argc == 2)
	{
		ft_printf("no custom values for julia, starting with default values\n");
		julia_base_init(f);
	}
	if (argc == 4 && !ft_strcmp(argv[1], "-j"))
	{
		f->julia_x = atodbl(argv[2]);
		f->julia_y = atodbl(argv[3]);
	}
	return (0);
}
