/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:13:59 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/20 15:34:35 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot(t_complex c, int max_iter)
{
	int			n;
	float		tmp;
	t_complex	z;

	n = 0;
	z.re = 0;
	z.im = 0;
	while (pow(z.re, 2) + pow(z.im, 2) < 4 && ++n < max_iter)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
	}
	if (n == max_iter)
		return (-1);
	else
		return (n);
}

void	draw_mandelbrot(t_fractal para, int xmin, int ymin, int xmax, int ymax)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = xmin - 1;
	while (++x <= WIN_W && x <= xmax)
	{
		y = ymin - 1;
		while (++y <= WIN_H && y <= ymax)
		{
			c.re = x * ((para.max_re - para.min_re) /
				(WIN_W)) + para.min_re;
			c.im = (-1 * y) * ((para.max_im - para.min_im) /
				(WIN_H)) + para.max_im;
			n = ft_mandelbrot(c, para.details_iter);
			if (n == -1)
				draw_pixel(para.image, x, y, 0);
			else
				draw_pixel(para.image, x, y, color_monochrome(n, 'R'));
		}
		--y;
	}
}
