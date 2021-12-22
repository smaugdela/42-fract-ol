/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:12:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/21 18:07:32 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_julia(t_complex c, t_complex param, int max_iter)
{
	int			n;
	float		tmp;

	n = 0;
	while (pow(c.re, 2) + pow(c.im, 2) < 4 && ++n < max_iter)
	{
		tmp = pow(c.re, 2) - pow(c.im, 2) + param.re;
		c.im = 2 * c.re * c.im + param.im;
		c.re = tmp;
	}
	if (n == max_iter)
		return (0);
	else
		return (n);
}

void	draw_julia(t_fractal para, int xmin, int ymin, int xmax, int ymax)
{
	t_complex   c;
	int			x;
	int			y;
	int			n;

	x = xmin - 1;
	while (++x < WIN_W && x <= xmax)
	{
		y = ymin - 1;
		while (++y < WIN_H && y <= ymax)
		{
			c.re = x * ((para.max_re - para.min_re) /
				(WIN_W)) + para.min_re;
			c.im = (-1 * y) * ((para.max_im - para.min_im) /
				(WIN_H)) + para.max_im;
			n = ft_julia(c, para.param, para.details_iter);
			if (n == -1)
				draw_pixel(para.image, x, y, 0);
			else
				draw_pixel(para.image, x, y, color_multi(n, para.details_iter));
		}
	}
}
