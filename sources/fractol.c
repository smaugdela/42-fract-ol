/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/10 13:51:08 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_display(t_display *display, char *win_name)
{
	display->mlx_ptr = mlx_init();
	if (display->mlx_ptr == NULL)
		ft_error("mlx_init");
	display->win_ptr = mlx_new_window(display->mlx_ptr, 
		WIN_WIDTH, WIN_HEIGHT, win_name);
	if (display->win_ptr == NULL)
	{
		mlx_destroy_display(display->mlx_ptr);
		free(display->mlx_ptr);
		ft_error("mlx_new_window");
	}
}

int main(void)
{
	t_display	display;
	t_image		image;

	init_display(&display, "Hello World!");
	image.display = &display;
	image.image_ptr = mlx_new_image(display.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	image.addr = mlx_get_data_addr(image.image_ptr,
		&image.bpp, &image.size_line, &image.endian);
	draw_circle(&image, build_circle(WIN_WIDTH / 3, WIN_HEIGHT / 3, 300, 0x80ff0000));
	draw_circle(&image, build_circle(WIN_WIDTH * 2 / 3, WIN_HEIGHT / 3, 300, 0x8000ff00));
	draw_circle(&image, build_circle(WIN_WIDTH / 2, WIN_HEIGHT * 2 / 3, 300, 0x800000ff));
	mlx_put_image_to_window(display.mlx_ptr, display.win_ptr, image.image_ptr, 0, 0);
	mlx_loop(display.mlx_ptr);
	destroy_n_free(&display);
	return (0);
}
