/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/13 15:33:05 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_display	*init_display(char *win_name)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (display == NULL)
		ft_error("malloc");
	display->mlx_ptr = mlx_init();
	if (display->mlx_ptr == NULL)
	{
		free(display);
		ft_error("mlx_init");
	}
	display->win_ptr = mlx_new_window(display->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, win_name);
	if (display->win_ptr == NULL)
	{
		free_n_destroy(NULL, display);
		ft_error("mlx_new_window");
	}
	return (display);
}

static int loop_handler(t_image *image)
{
	draw_circle(image, build_circle(WIN_WIDTH / 3, WIN_HEIGHT / 3, 350, 0xff0000));
	draw_circle(image, build_circle(WIN_WIDTH * 2 / 3, WIN_HEIGHT / 3, 350, 0x00ff00));
	draw_circle(image, build_circle(WIN_WIDTH / 2, WIN_HEIGHT * 2 / 3, 350, 0x0000ff));
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	return (0);
}

static int	keys_handler(int key_sym, t_image *image)
{
	printf("%d ", key_sym);
	if (key_sym == XK_Escape)
	{
//		mlx_destroy_window(image->display->mlx_ptr, image->display->win_ptr);
//		image->display->win_ptr = NULL;
		free_n_destroy(image, image->display);
		ft_putstr_fd("Thanks for using mlx! (Escape)\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

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
	ft_putstr_fd("Thanks for using mlx! (Main return)\n", 1);
	return (0);
}
