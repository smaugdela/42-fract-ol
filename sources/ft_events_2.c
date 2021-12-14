/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:57:13 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/14 12:20:19 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	red_cross_handler(t_image *image)
{
	free_n_destroy(image, image->display);
	ft_putstr_fd("\nClosing...\nThanks for using fract'ol!\n", 1);
	exit(EXIT_SUCCESS);
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
	(void)image;
	return (0);
}
