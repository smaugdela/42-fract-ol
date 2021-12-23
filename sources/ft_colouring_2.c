/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:00:07 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/23 11:52:05 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_grayscale(int n, int max_iter)
{
	int	x;

	x = -255 * ((float)n / (float)max_iter) + 255;
	return (x * 0x010000 + x * 0x000100 + x);
}

int	color_multi(int n, int max_iter)
{
	int		r;
	int		g;
	int		b;
	float	x;

	r = 0;
	g = 0;
	b = 0;
	x = (float)n / (float)max_iter;
	if (x >= 0 && x <= 0.5)
	{
		r = -510 * x - 255;
		g = 510 * x;
	}
	else if (x > 0.5)
	{
		g = -510 * x + 510;
		b = 510 * x - 255;
	}
	return (r * 0x010000 + g * 0x000100 + b);
}

int	color_lagoon(int n, int max_iter)
{
	int		r;
	int		g;
	int		b;
	float	x;

	r = 0;
	x = (float)n / (float)max_iter;
	b = 127.5 * x + 127.5;
	g = 255 * x;
	if (x >= 0.9)
		r = 2550 * x - 2295;
	return (r * 0x010000 + g * 0x000100 + b);
}

int	color_flame(int n, int max_iter)
{
	int		r;
	int		g;
	int		b;
	float	x;

	r = 255;
	b = 0;
	x = (float)n / (float)max_iter;
	g = 510 * x;
	if (x >= 0.5)
		g = -510 * x + 510;
	if (x >= 0.8 && x <= 0.9)
		r = -2550 * x + 2550;
	if (x >= 0.9)
	{
		b = 2550 * x - 2295;
		r = 0;
	}
	return (r * 0x010000 + g * 0x000100 + b);
}
