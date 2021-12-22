/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:00:07 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/22 18:00:59 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_grayscale(int n, int max_iter)
{
	int		N;

	N = -255 * ((float)n / (float)max_iter) + 255;
	return (N * 0x010000 + N * 0x000100 + N);
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
	else if (x > 0.5)
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
	x = (float)n / (float)max_iter;
	B = 127.5 * x + 127.5;
	G = 255 * x;
	if (x >= 0.9)
		R = 2550 * x - 2295;
	return (R * 0x010000 + G * 0x000100 + B);
}

int color_flame(int n, int max_iter)
{
	int		R;
	int		G;
	int		B;
	float	x;

	R = 255;
	B = 0;
	x = (float)n / (float)max_iter;
	G = 510 * x;
	if (x >= 0.6)
		G = -510 * x + 510;
	if (x >= 0.8 && x <= 0.9)
		R = -2550 * x + 2295;
	else if (x >= 0.9)
	{
		B = 2550 * x - 2295;
		R = 0;
	}
	return (R * 0x010000 + G * 0x000100 + B);
}