/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:13:59 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 19:05:42 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	draw_mandelbrot(t_image *image, t_fractal fractal)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
		{
			c.re = (x - (WIN_WIDTH / 2)) * ((fractal.max_re - fractal.min_re)
				/ (fractal.zoom * WIN_WIDTH));
			c.im = (y - (WIN_HEIGHT / 2)) * ((fractal.max_im - fractal.min_im)
				/ (fractal.zoom * WIN_HEIGHT));
			n = ft_mandelbrot(c);
			if (n == -1)
				draw_pixel(image, x, y, 0);
			else
				draw_pixel(image, x, y, color_monochrome(n, 'G'));
		}
	}
	real_axis_sym(image);
	draw_ui(image);
}
