/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:12:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/17 16:05:36 by smagdela         ###   ########.fr       */
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

static int	ft_julia(t_complex c, t_complex param)
{
	int			n;
	float		tmp;

	n = 0;
	while (pow(param.re, 2) + pow(param.im, 2) < 4 && ++n < MAX_ITER)
	{
		tmp = pow(param.re, 2) - pow(param.im, 2) + c.re;
		param.im = 2 * param.re * param.im + c.im;
		param.re = tmp;
	}
	if (n == MAX_ITER)
		return (-1);
	else
		return (n);
}

void	draw_julia(t_fractal params)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y <= WIN_H)
		{
			c.re = (x - (WIN_W / 2)) * ((params.max_re - params.min_re) / WIN_W);
			c.im = (y - (WIN_H / 2)) * ((params.max_im - params.min_im) / WIN_H);
			n = ft_julia(c, params.param);
			if (n == -1)
				draw_pixel(params.image, x, y, 0);
			else
				draw_pixel(params.image, x, y, color_monochrome(n, 'B'));
		}
	}
	real_axis_sym(params.image);
	draw_ui(params.image);
}
