/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:13:59 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/17 16:11:12 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	real_axis_sym(t_image *image)
{
	int	y;
	int	y_sym;
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		y_sym = WIN_H;
		while (y < WIN_H / 2)
		{
			draw_pixel(image, x, y_sym, get_pixel_color(x, y, image));
			++y;
			--y_sym;
		}
		++x;
	}
}

static int	ft_mandelbrot(t_complex c)
{
	int			n;
	float		tmp;
	t_complex	z;

	n = 0;
	z.re = 0;
	z.im = 0;
	while (pow(z.re, 2) + pow(z.im, 2) < 4 && ++n < MAX_ITER)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
	}
	if (n == MAX_ITER)
		return (-1);
	else
		return (n);
}

void	draw_mandelbrot(t_fractal params)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y <= WIN_H / 2)
		{
			c.re = (x - (WIN_W / 2)) * ((params.max_re - params.min_re)
				/ (params.zoom * WIN_W));
			c.im = (y - (WIN_H / 2)) * ((params.max_im - params.min_im)
				/ (params.zoom * WIN_H));
			n = ft_mandelbrot(c);
			if (n == -1)
				draw_pixel(params.image, x, y, 0);
			else
				draw_pixel(params.image, x, y, color_monochrome(n, 'G'));
		}
	}
	real_axis_sym(params.image);
	draw_ui(params.image);
}
