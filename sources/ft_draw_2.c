/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:23:31 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/15 16:22:00 by smagdela         ###   ########.fr       */
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
	else if (color == 'C')
		return ((0x0000ffff * n / MAX_ITER) & 0x0000ffff);
	else if (color == 'M')
		return ((0x00ff00ff * n / MAX_ITER) & 0x00ff00ff);
	else if (color == 'Y')
		return ((0x00ffff00 * n / MAX_ITER) & 0x00ffff00);
	else
		return ((0x00ffffff * n / MAX_ITER) & 0x00ffffff);
}

int	color_continuous(float nu)
{
	uint8_t	color_bytes[4];
	int				color;

	color_bytes[0] = (uint8_t)255;
	color_bytes[1] = (uint8_t)((sin(0.1 * nu + 0) + 1) * 127.5);
	color_bytes[2] = (uint8_t)((sin(0.1 * nu + 3.14 / 2) + 1) * 127.5);
	color_bytes[3] = (uint8_t)((sin(0.1 * nu + 3.14) + 1) * 127.5);
	color = 0;
	color = color | color_bytes[0] << 24;
	color = color | color_bytes[1] << 16;
	color = color | color_bytes[2] << 8;
	color = color | color_bytes[3];
	return (color);
}
