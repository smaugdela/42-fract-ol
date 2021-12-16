/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 18:58:07 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pixel_color(int x, int y, t_image *image)
{
	char	*pixel;

	pixel = image->addr + (y * image->size_line + x * (image->bpp / 8));
	return (*(int *)pixel);
}

int	color_monochrome(int n, char color)
{
	if (color == 'R')
		return ((0x00ff0000 * n / MAX_ITER) & 0x00ff0000);
	else if (color == 'G')
		return ((0x0000ff00 * n / MAX_ITER) & 0x0000ff00);
	else if (color == 'B')
		return ((0x000000ff * n / MAX_ITER) & 0x000000ff);
	/* Only primary colors are working, not composed ones as below. */
	else if (color == 'C')
		return ((0x0000ffff * n / MAX_ITER) & 0x0000ffff);
	else if (color == 'M')
		return ((0x00ff00ff * n / MAX_ITER) & 0x00ff00ff);
	else if (color == 'Y')
		return ((0x00ffff00 * n / MAX_ITER) & 0x00ffff00);
	else
		return ((0x00ffffff * n / MAX_ITER) & 0x00ffffff);
}

int	revert_color(int color)
{
	uint8_t	color_bytes[4];

	color_bytes[0] = (uint8_t)255;
	color_bytes[1] = (uint8_t)((127.5 + (uint8_t)(color >> 16)) % 255);
	color_bytes[2] = (uint8_t)((127.5 + (uint8_t)(color >> 8)) % 255);
	color_bytes[3] = (uint8_t)((127.5 + (uint8_t)(color)) % 255);
	color = 0;
	color = color | color_bytes[0] << 24;
	color = color | color_bytes[1] << 16;
	color = color | color_bytes[2] << 8;
	color = color | color_bytes[3];
	return (color);
}
