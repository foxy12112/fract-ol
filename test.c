/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:26:49 by ldick             #+#    #+#             */
/*   Updated: 2024/05/11 16:35:12 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_comp	z;
	t_comp	c;
	double	tmp_real;
	int		i;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = 0.25;
	c.y = 0.4;
	while (i < 42)
	{
		tmp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y;
		z.x = tmp_real;
		z.x += c.x;
		z.y += c.y;
		i++;
		printf("iteration n -> %d real %f imaginary %f\n", i, z.x, z.y);
	}
	return (0);
}
