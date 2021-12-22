/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/22 19:47:02 by smagdela         ###   ########.fr       */
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

void reset_ui(t_image *image)
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
	{
		free_n_destroy(image, image->display);
		ft_putstr_fd("Escaping...\n\033[0;32mThanks for using fract'ol!\033[0m\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (key_sym == XK_h)
		reset_ui(image);
	else if (key_sym == XK_Right && !image->fractal.display_ui)
		cam_right(image, 0.1 * (image->fractal.max_re - image->fractal.min_re));
	else if (key_sym == XK_Left && !image->fractal.display_ui)
		cam_left(image, 0.1 * (image->fractal.max_re - image->fractal.min_re));
	else if (key_sym == XK_Up && !image->fractal.display_ui)
		cam_up(image, 0.1 * (image->fractal.max_im - image->fractal.min_im));
	else if (key_sym == XK_Down && !image->fractal.display_ui)
		cam_down(image, 0.1 * (image->fractal.max_im - image->fractal.min_im));
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

int	keys_rev_handler(int key_sym, t_image *image)
{
	(void)image;
	(void)key_sym;
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
/*
Button value:
	clic gauche = 1
	clic droit = 3
	clic molette = 2
	molette /\ = 4
	molette \/ = 5
*/
int button_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		image->fractal.max_im += 0.2 * (image->fractal.max_im - image->fractal.min_im);
		image->fractal.min_im -= 0.2 * (image->fractal.max_im - image->fractal.min_im);
		image->fractal.max_re += 0.2 * (image->fractal.max_re - image->fractal.min_re);
		image->fractal.min_re -= 0.2 * (image->fractal.max_re - image->fractal.min_re);
		image->fractal.render = TRUE;
	}
	else if (button == 4)
	{
		image->fractal.max_im -= 0.2 * (image->fractal.max_im - image->fractal.min_im);
		image->fractal.min_im += 0.2 * (image->fractal.max_im - image->fractal.min_im);
		image->fractal.max_re -= 0.2 * (image->fractal.max_re - image->fractal.min_re);
		image->fractal.min_re += 0.2 * (image->fractal.max_re - image->fractal.min_re);
		image->fractal.render = TRUE;
	}
	return (0);
}

int	button_rev_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	(void)button;
	(void)image;
	return (0);
}
