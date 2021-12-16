/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 14:46:18 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_events(t_display *display, t_image *image)
{
	mlx_loop_hook(display->mlx_ptr, &loop_handler, image);
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &keys_handler, image);
	mlx_hook(display->win_ptr, KeyRelease, KeyReleaseMask,
		&keys_rev_handler, image);
	mlx_hook(display->win_ptr, DestroyNotify, StructureNotifyMask,
		&red_cross_handler, image);
	mlx_hook(display->win_ptr, ButtonPress, ButtonPressMask,
		&button_handler, image);
	mlx_hook(display->win_ptr, ButtonRelease, ButtonReleaseMask,
		&button_rev_handler, image);
	mlx_hook(display->win_ptr, MotionNotify, PointerMotionMask,
		&pointer_handler, image);
	return (0);
}

int	main(void)
{
	t_display	*display;
	t_image		*image;
	t_fractal	julia;
	t_complex	param;

	display = init_display("Hello World!");
	image = init_image(display);
	init_events(display, image);
	param.re = 0;
	param.im = 0;
/*
	mandelbrot.max_im = 1.1;
	mandelbrot.min_im = -1.1;
	mandelbrot.max_re = 0.01;
	mandelbrot.min_re = -3.5;
	mandelbrot.param = param;
	draw_mandelbrot(image, mandelbrot);

	julia.max_im = 1;
	julia.min_im = -1;
	julia.max_re = 1;
	julia.min_re = -1;
	julia.param = param;
	draw_julia(image, julia);
	image->fractal = julia;
*/
	mlx_loop(display->mlx_ptr);
	free_n_destroy(image, display);
	ft_putstr_fd("\nStopping...\nThanks for using fract'ol!\n", 1);
	return (0);
}
