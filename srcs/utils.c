/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:44:11 by ldick             #+#    #+#             */
/*   Updated: 2024/05/15 12:57:43 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double map(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
}

t_comp	sum_complex(t_comp z1, t_comp z2)
{
	t_comp	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_comp	square_complex(t_comp z)
{
	t_comp result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}