/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/21 18:08:18 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pixel_color(int x, int y, t_image *image)
{
	char	*pixel;

	if (x > WIN_W || x < 0 || y > WIN_H || y < 0)
		return (42);
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
	else
		return ((0x00ffffff * n / MAX_ITER) & 0x00ffffff);
}

int color_multi(int n, int max_iter)
{
	int		R;
	int		G;
	int		B;
	float	x;

	R = 0;
	G = 0;
	B = 0;
	x = (float)n / (float)max_iter;
	if (x >= 0 && x <= 0.5)
	{
		R = -510 * x - 255;
		G = 510 * x;
	}
	else if (x > 0.5 && x <= 1)
	{
		G = -510 * x + 510;
		B = 510 * x - 255;
	}
	return (R * 0x010000 + G * 0x000100 + B);
}

int blue_multi(int n, int max_iter)
{
	int		B;
	float	x;

	B = 0;
	x = (float)n / (float)max_iter;
	B = 510 * x - 255;
	return (0.5 * B * 0x010000 + 0.5 * B * 0x000100 + B);
}
