/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:54:46 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 18:55:05 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

float	ft_mandelbrot(t_complex c)
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
		return (n + 1 - (log(2) / complex_magnitude(z)) / log(2));
}

void	draw_mandelbrot(t_image *image, t_fractal fractal)
{
	t_complex   c;
	int			x;
	int			y;
	float		nu;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			c.re = (x - (WIN_WIDTH / 2)) * ((fractal.max_re - fractal.min_re) / WIN_WIDTH);
			c.im = (y - (WIN_HEIGHT / 2)) * ((fractal.max_im - fractal.min_im) / WIN_HEIGHT);
			nu = ft_mandelbrot(c);
			if (nu == -1)
				draw_pixel(image, x, y, 0);
			else
				draw_pixel(image, x, y, color_continuous(nu));
		}
	}
	draw_ui(image);
}
