/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:17:43 by ldick             #+#    #+#             */
/*   Updated: 2024/05/13 20:04:03 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int my_key_handler(mlx_key_data_t mkd, void *data)
{
	t_fractal *f;
	
	f = (t_fractal *) data;
	if (mkd.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(f->mlx_window, f->img);
		mlx_terminate(f->mlx_window);
		exit(EXIT_SUCCESS);
	}
	if (mdk.key == MLX_KEY_LEFT)

	return (0);
}