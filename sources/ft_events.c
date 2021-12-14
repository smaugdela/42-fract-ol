/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/14 12:42:53 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(t_image *image)
{	
	(void)image;
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
	else if (key_sym == XK_q)
		draw_circle(image, build_circle(WIN_WIDTH / 3, WIN_HEIGHT / 3,
			350, 0xff0000));
	else if (key_sym == XK_w)
		draw_circle(image, build_circle(WIN_WIDTH * 2 / 3, WIN_HEIGHT / 3,
			350, 0x00ff00));
	else if (key_sym == XK_e)
		draw_circle(image, build_circle(WIN_WIDTH / 2, WIN_HEIGHT * 2 / 3,
			350, 0x0000ff));
	ft_putchar_fd((char)key_sym, 1);
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	return (0);
}

int	keys_rev_handler(int key_sym, t_image *image)
{
    int color;

    color = 0;
    if (key_sym == XK_q)
		draw_circle(image, build_circle(WIN_WIDTH / 3, WIN_HEIGHT / 3,
			350, color));
	else if (key_sym == XK_w)
		draw_circle(image, build_circle(WIN_WIDTH * 2 / 3, WIN_HEIGHT / 3,
			350, color));
	else if (key_sym == XK_e)
		draw_circle(image, build_circle(WIN_WIDTH / 2, WIN_HEIGHT * 2 / 3,
			350, color));
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_image *image)
{
	if (button == 1)
	{
		draw_circle(image, build_circle(x, y, 50, 0xffffff));
		mlx_put_image_to_window(image->display->mlx_ptr,
			image->display->win_ptr, image->image_ptr, 0, 0);
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
int	mouse_rev_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	if (button == 1)
		clear_window(image, 0);
	return (0);
}
