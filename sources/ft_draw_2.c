/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:23:31 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 15:10:07 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_monochrome(int n, char color)
{
	if (color == 'R')
		return ((0x00ff0000 * n / MAX_ITER) & 0x00ff0000);
	else if (color == 'G')
		return ((0x0000ff00 * n / MAX_ITER) & 0x0000ff00);
	else if (color == 'B')
		return ((0x000000ff * n / MAX_ITER) & 0x000000ff);
	/* Only primary colors are working, not composed as below. */
	else if (color == 'C')
		return ((0x0000ffff * n / MAX_ITER) & 0x0000ffff);
	else if (color == 'M')
		return ((0x00ff00ff * n / MAX_ITER) & 0x00ff00ff);
	else if (color == 'Y')
		return ((0x00ffff00 * n / MAX_ITER) & 0x00ffff00);
	else
		return ((0x00ffffff * n / MAX_ITER) & 0x00ffffff);
}
