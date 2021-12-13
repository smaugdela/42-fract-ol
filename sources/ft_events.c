/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:45:38 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/13 15:53:16 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int loop_handler(t_image *image)
{
	draw_circle(image, build_circle(WIN_WIDTH / 3, WIN_HEIGHT / 3, 350, 0xff0000));
	draw_circle(image, build_circle(WIN_WIDTH * 2 / 3, WIN_HEIGHT / 3, 350, 0x00ff00));
	draw_circle(image, build_circle(WIN_WIDTH / 2, WIN_HEIGHT * 2 / 3, 350, 0x0000ff));
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	return (0);
}

int	keys_handler(int key_sym, t_image *image)
{
	printf("%d ", key_sym);
	if (key_sym == XK_Escape)
	{
		free_n_destroy(image, image->display);
		ft_putstr_fd("Escaping...\nThanks for using fract'ol!\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
