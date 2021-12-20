/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:49:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/20 15:26:17 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cam_right(t_image *image)
{
	int x;
	int y;
	int	step;

	step = 5;
	if (WIN_W > 100)
		step *= WIN_W / 100;
	x = 0;
	while (x + step <= WIN_W)
	{
		y = 0;
		while (y <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x + step, y, image));
			++y;
		}
		++x;
	}
	image->fractal.max_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.min_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.draw_ft(image->fractal, x, 0, WIN_W, WIN_H);
}

void	cam_left(t_image *image)
{
	int x;
	int y;
	int	step;

	step = 5;
	if (WIN_W > 100)
		step *= WIN_W / 100;
	x = WIN_W;
	while (x - step >= 0)
	{
		y = 0;
		while (y <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x - step, y, image));
			++y;
		}
		--x;
	}
	image->fractal.max_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.min_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.draw_ft(image->fractal, 0, 0, x, WIN_H);
}

void	cam_up(t_image *image)
{
	int x;
	int y;
	int	step;

	step = 5;
	if (WIN_H > 100)
		step *= WIN_H / 100;
	x = 0;
	while (x <= WIN_W)
	{
		y = WIN_H;
		while (y - step >= 0)
		{
			draw_pixel(image, x, y, get_pixel_color(x, y - step, image));
			++y;
		}
		++x;
	}
	image->fractal.max_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.min_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.draw_ft(image->fractal, x, 0, WIN_W, y);
}

void	cam_down(t_image *image)
{
	int x;
	int y;
	int	step;

	step = 5;
	if (WIN_H > 100)
		step *= WIN_H / 100;
	x = 0;
	while (x <= WIN_W)
	{
		y = 0;
		while (y + step <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x, y + step, image));
			++y;
		}
		++x;
	}
	image->fractal.max_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.min_re += step
		* (image->fractal.max_re - image->fractal.min_re) / WIN_W;
	image->fractal.draw_ft(image->fractal, x, y, WIN_W, WIN_H);
}
