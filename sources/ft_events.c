/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 18:52:55 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(t_image *image)
{	
	if (image->fractal.render == TRUE)
	{
		mlx_put_image_to_window(image->display->mlx_ptr,
			image->display->win_ptr, image->image_ptr, 0, 0);
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
	{
		/* Ici il faut afficher le UI d'aide (afficher les differentes touches, les parametres de fractale, etc...) */
		ft_putchar_fd((char)key_sym, 1);
		image->fractal.render = TRUE;
	}
	return (0);
}

int	keys_rev_handler(int key_sym, t_image *image)
{
	int	color;

	color = 0;
	if (key_sym == XK_h)
	{
		/* Ici il faut eteindre le UI d'aide (afficher les differentes touches, les parametres de fractale, etc...) */
		ft_putchar_fd((char)key_sym, 1);
		image->fractal.render = TRUE;
	}
	return (0);
}

int	pointer_handler(int x, int y, t_image *image)
{
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
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
		image->fractal.render = TRUE;
	}
	else if (button == 5)
	{
		image->fractal.zoom -= 0.1;
		image->fractal.render = TRUE;
	}
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
