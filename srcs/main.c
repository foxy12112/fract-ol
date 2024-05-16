/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:06 by ldick             #+#    #+#             */
/*   Updated: 2024/05/16 14:42:24 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	f;

	f.name = argv[1];
	//turns the arguments 2 and 3 into doubles frmoa  string
	if (argc == 4)
	{
		f.julia_x = atodbl(argv[2]);
		f.julia_y = atodbl(argv[3]);
	}

	// makes the name, turns -m to Mandelbrot and -J into Julia
	fancy_name_maker(&f);
	// checks if the set you choose is mandelbrot or julia ----9------------------TODO
	/*
	if (ft_strcmp(f.name, "Mandelbrot") && ft_strcmp(f.name, "Julia"))
		return (1);
	*/
	//simply a small leakcheck programm thats executed at exit---------------------REMOVE BEFoRE EVALUATIONS
	atexit(leakcheck);
	//initializes the fractal, goes over to render.c
	init_fractal(&f);
	fractal_render(&f);
	mlx_key_hook(f.mlx_window, my_key_handler, &f);
	mlx_scroll_hook(f.mlx_window, my_scroll_func, &f);
	mlx_loop(f.mlx_window);
	return (0);
}
