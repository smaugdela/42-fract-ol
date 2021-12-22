/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/22 22:57:58 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(t_image *image)
{	
	if (image->fractal.render == TRUE)
	{
		image->fractal.draw_ft(image->fractal, 0, 0, WIN_W, WIN_H);
		mlx_put_image_to_window(image->display->mlx_ptr,
			image->display->win_ptr, image->image_ptr, 0, 0);
		mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
			15, 20, 0x00ffffff, "H for help");
		image->fractal.render = FALSE;
	}
	else if (image->fractal.display_ui == TRUE)
		draw_ui(image);
	return (0);
}

void	reset_ui(t_image *image)
{
	if (image->fractal.display_ui == TRUE)
	{
		image->fractal.display_ui = FALSE;
		image->fractal.draw_ft(image->fractal, WIN_W / 3 + 29, WIN_W / 3 - 1,
			WIN_W / 3 + 230, WIN_H / 3 + 101);
		mlx_put_image_to_window(image->display->mlx_ptr,
			image->display->win_ptr, image->image_ptr, 0, 0);
		mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
			15, 20, 0x00ffffff, "H for help");
	}
	else
		image->fractal.display_ui = TRUE;
}

int	keys_handler(int key_sym, t_image *image)
{
	if (key_sym == XK_Escape)
		red_cross_handler(image);
	else if (key_sym == XK_h)
		reset_ui(image);
	else if (key_sym == XK_Up || key_sym == XK_Down
		|| key_sym == XK_Left || key_sym == XK_Right)
		cams(image, key_sym);
	else if (key_sym == XK_w)
		zoom_in(image);
	else if (key_sym == XK_q)
		zoom_out(image);
	else if (key_sym == XK_KP_Add && image->fractal.max_iter < 100)
	{
		image->fractal.max_iter += 4;
		image->fractal.render = TRUE;
	}
	else if (key_sym == XK_KP_Subtract && image->fractal.max_iter >= 10)
	{
		image->fractal.max_iter -= 4;
		image->fractal.render = TRUE;
	}
	return (0);
}

int	pointer_handler(int x, int y, t_image *image)
{
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		image->fractal.param.re = x
			* ((image->fractal.max_re - image->fractal.min_re)
				/ (WIN_W)) + image->fractal.min_re;
		image->fractal.param.im = (-1 * y)
			* ((image->fractal.max_im - image->fractal.min_im)
				/ (WIN_H)) + image->fractal.max_im;
		image->fractal.render = TRUE;
	}
	return (0);
}

int	button_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	if (button == 5)
		zoom_out(image);
	else if (button == 4)
		zoom_in(image);
	return (0);
}
/*
Button value:
	clic gauche = 1
	clic droit = 3
	clic molette = 2
	molette /\ = 4
	molette \/ = 5
*/
