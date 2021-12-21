/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:49:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/21 15:29:47 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cam_right(t_image *image, float step)
{
	int x;
	int y;
	int	stepix;

	stepix = step * WIN_W / (image->fractal.max_re - image->fractal.min_re);
	x = 0;
	while (x + stepix <= WIN_W)
	{
		y = 0;
		while (y <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x + stepix, y, image));
			++y;
		}
		++x;
	}
	image->fractal.max_re += step;
	image->fractal.min_re += step;
	image->fractal.draw_ft(image->fractal, x - 1, 0, WIN_W, WIN_H);
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
		15, 20, 0x00ffffff, "H for help");
}

void	cam_left(t_image *image, float step)
{
	int x;
	int y;
	int	stepix;

	stepix = step * WIN_W / (image->fractal.max_re - image->fractal.min_re);
	x = WIN_W;
	while (x - stepix >= 0)
	{
		y = 0;
		while (y <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x - stepix, y, image));
			++y;
		}
		--x;
	}
	image->fractal.max_re -= step;
	image->fractal.min_re -= step;
	image->fractal.draw_ft(image->fractal, 0, 0, x + 1, WIN_H);
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
		15, 20, 0x00ffffff, "H for help");
}

void	cam_up(t_image *image, float step)
{
	int x;
	int y;
	int	stepix;

	stepix = step * WIN_H / (image->fractal.max_im - image->fractal.min_im);
	x = 0;
	while (x <= WIN_W)
	{
		y = WIN_H;
		while (y - stepix >= 0)
		{
			draw_pixel(image, x, y, get_pixel_color(x, y - stepix, image));
			--y;
		}
		++x;
	}
	image->fractal.max_im += step;
	image->fractal.min_im += step;
	image->fractal.draw_ft(image->fractal, 0, 0, WIN_W, y + 1);
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
		15, 20, 0x00ffffff, "H for help");
}

void	cam_down(t_image *image, float step)
{
	int x;
	int y;
	int	stepix;

	stepix = step * WIN_H / (image->fractal.max_im - image->fractal.min_im);
	x = 0;
	while (x <= WIN_W)
	{
		y = 0;
		while (y + stepix <= WIN_H)
		{
			draw_pixel(image, x, y, get_pixel_color(x, y + stepix, image));
			++y;
		}
		++x;
	}
	image->fractal.max_im -= step;
	image->fractal.min_im -= step;
	image->fractal.draw_ft(image->fractal, 0, y - 1, WIN_W, WIN_H);
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
		15, 20, 0x00ffffff, "H for help");
}
