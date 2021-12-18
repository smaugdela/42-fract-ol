/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:13:59 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/18 16:24:33 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	real_axis_sym(t_image *image, int real_axis)
{
	int	y;
	int	y_sym;
	int	x;

	if (real_axis <= 0 || real_axis >= WIN_H)
		return ;
	x = 0;
	while (x < WIN_W)
	{
		if (real_axis % 2 == 0)
		{
			y = real_axis;
			y_sym = real_axis;
		}
		else
		{
			y = real_axis - 1;
			y_sym = real_axis + 1;
		}
		while (++y <= WIN_H && --y_sym >= 0)
		{
			if (real_axis >= WIN_H / 2)
				draw_pixel(image, x, y, get_pixel_color(x, y_sym, image));
			else
				draw_pixel(image, x, y_sym, get_pixel_color(x, y, image));
		}
		++x;
	}
}

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

void	draw_mandelbrot(t_fractal params)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = -1;
	while (++x <= WIN_W)
	{
		c.im = 0;
		if (fabs(params.max_im) >= fabs(params.min_im))
		{
			y = -1;
			while (++y <= WIN_H && c.im >= 0)
			{
				c.re = x * ((params.max_re - params.min_re) /
					(WIN_W)) + params.min_re;
				c.im = (-1 * y) * ((params.max_im - params.min_im) /
					(WIN_H)) + params.max_im;
				n = ft_mandelbrot(c, params.details_iter);
				if (n == -1)
					draw_pixel(params.image, x, y, 0);
				else
					draw_pixel(params.image, x, y, color_monochrome(n, 'R'));
			}
			--y;
		}
		else
		{
			y = WIN_H + 1;
			while (--y >= 0 && c.im <= 0)
			{
				c.re = x * ((params.max_re - params.min_re) /
					(WIN_W)) + params.min_re;
				c.im = (-1 * y) * ((params.max_im - params.min_im) /
					(WIN_H)) + params.max_im;
				n = ft_mandelbrot(c, params.details_iter);
				if (n == -1)
					draw_pixel(params.image, x, y, 0);
				else
					draw_pixel(params.image, x, y, color_monochrome(n, 'R'));
			}
			++y;
		}
	}
	printf("real_axis = %d\n", y);
	real_axis_sym(params.image, y);
}
