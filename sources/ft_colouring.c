/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/22 11:24:02 by smagdela         ###   ########.fr       */
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

int	color_bnw(int n, int max_iter)
{
	(void)n;
	(void)max_iter;
	return(0xffffff);
}

int	color_grayscale(int n, int max_iter)
{
	int		N;

	N = -255 * ((float)n / (float)max_iter) + 255;
	return (N * 0x010000 + N * 0x000100 + N);
}

int color_r(int n, int max_iter)
{
	int	R;

	R = -255 * ((float)n / (float)max_iter) + 255;
	return (0x010000 * R);
}

int color_g(int n, int max_iter)
{
	int	G;

	G = -255 * ((float)n / (float)max_iter) + 255;
	return (0x000100 * G);
}

int color_b(int n, int max_iter)
{
	int	B;

	B = -255 * ((float)n / (float)max_iter) + 255;
	return (B);
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

int color_lagoon(int n, int max_iter)
{
	int		R;
	int		G;
	int		B;
	float	x;

	R = 0;
	G = 0;
	B = 255;
	x = (float)n / (float)max_iter;
	if (x >= 0 && x <= 0.5)
	{
		R = -510 * x - 255;
		G = 510 * x;
	}
	else if (x > 0.5 && x <= 1)
	{
		G = -510 * x + 510;
	}
	return (R * 0x010000 + G * 0x000100 + B);
}

int color_flame(int n, int max_iter)
{
	int		R;
	int		G;
	int		B;
	float	x;

	R = 255;
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
	}
	return (R * 0x010000 + G * 0x000100 + B);
}