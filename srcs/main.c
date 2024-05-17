/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:06 by ldick             #+#    #+#             */
/*   Updated: 2024/05/17 15:35:23 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	f;

	f.name = argv[1];
	if (argc == 1 || argc > 4)
	{
		info_message(argv);
		return (0);
	}
	if (argc == 4 && ft_strcmp(f.name, "Julia"))
	{
		f.julia_x = atodbl(argv[2]);
		f.julia_y = atodbl(argv[3]);
	}
	atexit(leakcheck);
	fancy_name_maker(&f);
	init_fractal(&f);
	fractal_render(&f);
	mlx_key_hook(f.mlx_window, my_key_handler, &f);
	mlx_scroll_hook(f.mlx_window, my_scroll_func, &f);
	mlx_loop(f.mlx_window);
	mlx_terminate(f.mlx_window);
	return (0);
}
