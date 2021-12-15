/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:13:59 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/15 10:44:34 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_complex c)
{
	int			i;
	float		tmp;
	t_complex	z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (pow(z.re, 2) + pow(z.im, 2) < 4 && ++i < MAX_ITER)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
	}
	return (i);
}

void	draw_fractal(t_image *image, t_fractal fractal)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			c.re = (x - (WIN_WIDTH / 2)) * ((fractal.max_re - fractal.min_re) / WIN_WIDTH);
			c.im = (y - (WIN_HEIGHT / 2)) * ((fractal.max_im - fractal.min_im) / WIN_HEIGHT);
			n = fractal.ft_fractal(c);
			if (n >= MAX_ITER)
				draw_pixel(image, x, y, 0);
			else
				draw_pixel(image, x, y, color_monochrome(n, 'G'));
		}
	}
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
}
