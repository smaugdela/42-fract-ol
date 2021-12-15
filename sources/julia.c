/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:12:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/15 18:35:39 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_julia(t_complex c, t_fractal julia)
{
	int			n;
	float		tmp;

	n = 0;
	while (pow(julia.param.re, 2) + pow(julia.param.im, 2) < 4 && ++n < MAX_ITER)
	{
		tmp = pow(julia.param.re, 2) - pow(julia.param.im, 2) + c.re;
		julia.param.im = 2 * julia.param.re * julia.param.im + c.im;
		julia.param.re = tmp;
	}
	if (n == MAX_ITER)
		return (-1);
	else
		return (n + 1 - (log(2) / complex_magnitude(julia.param)) / log(2));
}

void	draw_julia(t_image *image, t_fractal julia)
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
			c.re = (x - (WIN_WIDTH / 2)) * ((julia.max_re - julia.min_re) / WIN_WIDTH);
			c.im = (y - (WIN_HEIGHT / 2)) * ((julia.max_im - julia.min_im) / WIN_HEIGHT);
			nu = ft_julia(c, julia);
			if (nu == -1)
				draw_pixel(image, x, y, 0);
			else
				draw_pixel(image, x, y, color_continuous(nu));
		}
	}
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
}
