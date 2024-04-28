/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:26:49 by ldick             #+#    #+#             */
/*   Updated: 2024/04/28 07:34:51 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main-libs/libs.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

	char *str = "abcdefg111gggg";
	while(*str)
	{
	printf("%d\n", ft_isalpha(*str));
	str++;
	}
}
