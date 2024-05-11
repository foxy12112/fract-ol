/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:28:09 by ldick             #+#    #+#             */
/*   Updated: 2024/05/11 18:23:50 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "main-libs/libs.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <errno.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;	//bytes per pixel
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_hooks;
	void	*mlx_window;
	t_img	img;
	double	escape_val;
}	t_fractal;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

# define WIDTH 800
# define HIGHT 800
# define MAX_ITERATIONS 69

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define MAGENTA	0xFF00FF
# define CYAN		0x00FFFF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define GRAY		0x808080
# define BROWN		0xA52A2A
# define PINK		0xFFC0CB
# define LIME		0x00FF00
# define TEAL		0x008080
# define OLIVE		0x808000
# define NAVY		0x000080
# define MAROON		0x800000
# define SILVER		0xC0C0C0
# define GOLD		0xFFD700
# define INDIGO		0x4B0082
# define VIOLET		0xEE82EE


void	init_fractal(t_fractal *f);
void handle_pixel(int x, int y, t_fractal *f);
void fractal_render(t_fractal *f);
double map(double unscaled, double new_min, double new_max, double old_min, double old_max);
t_comp	square_complex(t_comp z);
t_comp	sum_complex(t_comp z1, t_comp z2);


#endif