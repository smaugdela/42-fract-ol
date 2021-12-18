/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/18 14:05:41 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(t_image *image)
{	
	if (image->fractal.render == TRUE)
	{
		image->fractal.draw_ft(image->fractal);
		mlx_put_image_to_window(image->display->mlx_ptr,
			image->display->win_ptr, image->image_ptr, 0, 0);
		draw_ui(image, image->fractal.display_ui);
		image->fractal.render = FALSE;
	}
	return (0);
}

int	keys_handler(int key_sym, t_image *image)
{
	if (key_sym == XK_Escape)
	{
		free_n_destroy(image, image->display);
		ft_putstr_fd("\nEscaping...\nThanks for using fract'ol!\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (key_sym == XK_h)
		image->fractal.display_ui = TRUE;
	else if (key_sym == XK_Right)
	{
		image->fractal.max_re += 0.1;
		image->fractal.min_re += 0.1;
	}
	else if (key_sym == XK_Left)
	{
		image->fractal.max_re -= 0.1;
		image->fractal.min_re -= 0.1;
	}
	else if (key_sym == XK_Up)
	{
		image->fractal.max_im += 0.1;
		image->fractal.min_im += 0.1;
	}
	else if (key_sym == XK_Down)
	{
		image->fractal.max_im -= 0.1;
		image->fractal.min_im -= 0.1;
	}
	else if (key_sym == XK_KP_Add)
		image->fractal.details_iter += 5;
	else if (key_sym == XK_KP_Subtract)
		image->fractal.details_iter -= 5;
	image->fractal.render = TRUE;
	return (0);
}

int	keys_rev_handler(int key_sym, t_image *image)
{
	int	color;

	color = 0;
	if (key_sym == XK_h)
	{
		image->fractal.display_ui = FALSE;
		image->fractal.render = TRUE;
	}
	return (0);
}

int	pointer_handler(int x, int y, t_image *image)
{
	(void)image;
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
	{
		ft_putstr_fd("Mouse coordinates = (", 1);
		ft_putnbr_fd(x, 1);
		ft_putstr_fd(", ", 1);
		ft_putnbr_fd(y, 1);
		ft_putstr_fd(")\n", 1);
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
	if (button == 1)
		mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
			x + 10, y + 10, 0xffff00, "Click!");
	else if (button == 4)
	{
		image->fractal.zoom += 0.1;
		image->fractal.details_iter = MAX_ITER;
		image->fractal.render = TRUE;
	}
	else if (button == 5)
	{
		image->fractal.zoom -= 0.1;
		image->fractal.details_iter = MAX_ITER;
		image->fractal.render = TRUE;
	}
	ft_putnbr_fd(button, 1);
	return (0);
}

int	button_rev_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	if (button == 1)
		image->fractal.render = TRUE;
	return (0);
}
