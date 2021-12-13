/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/13 15:53:19 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	DEBUGGER:

int			i = 0;
printf("OK %d\n", ++i);
printf("Init OK\ndisplay = %p\ndisplay->mlx_ptr = %p\ndisplay->win_ptr = %p\n"
	, display, display->mlx_ptr, display->win_ptr);
printf("image  = %p\nimage->display = %p\nimage->image_ptr = %p\nimage->addr = %p\n"
	, image, image->display, image->image_ptr, image->addr);
*/

int main(void)
{
	t_display	*display;
	t_image		*image;

	display = init_display("Hello World!");
	image = init_image(display);

	mlx_loop_hook(display->mlx_ptr, &loop_handler, image);
//	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &keys_handler, &display);
	mlx_key_hook(display->win_ptr, &keys_handler, image);

	mlx_loop(display->mlx_ptr);

	free_n_destroy(image, display);
	ft_putstr_fd("Stopping...\nThanks for using fract'ol!\n", 1);
	return (0);
}
