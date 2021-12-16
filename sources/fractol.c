/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 18:51:45 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_args(int argc, char *argv, char **sets)
{
	while (argc == 2 && sets != NULL)
	{
		if (ft_strncmp(argv, *sets, ft_max(ft_strlen(argv), ft_strlen(*sets)))
			== 0)
			return ;
		++sets;
	}
	ft_pustr_fd("Bad input:\n", 2);
	ft_pustr_fd("Usage: ./fractol <name of fractal set>\n", 1);
	ft_putstr_fd("List of available sets:\n - Mandelbrot\n - Julia\n", 1);
	exit (42);
}

static void	init_events(t_display *display, t_image *image)
{
	mlx_loop_hook(display->mlx_ptr, &loop_handler, image);
	mlx_hook(display->win_ptr, DestroyNotify, StructureNotifyMask,
		&red_cross_handler, image);
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &keys_handler, image);
	mlx_hook(display->win_ptr, KeyRelease, KeyReleaseMask,
		&keys_rev_handler, image);
	mlx_hook(display->win_ptr, ButtonPress, ButtonPressMask,
		&button_handler, image);
	mlx_hook(display->win_ptr, ButtonRelease, ButtonReleaseMask,
		&button_rev_handler, image);
	mlx_hook(display->win_ptr, MotionNotify, PointerMotionMask,
		&pointer_handler, image);
}

static t_fractal	init_fractal(t_image *image, char *set)
{
	t_fractal	fractal;

	fractal.max_re = 1;
	fractal.min_re = -4;
	fractal.max_im = 1.5;
	fractal.min_im = -1.5;
	fractal.zoom = 1.0;
	fractal.details_iter = MAX_ITER;
	fractal.render = TRUE;
	image->fractal = fractal;
	return (fractal);
}

int	main(int argc, char *argv)
{
	t_display	*display;
	t_image		*image;
	t_fractal	fractal;

	check_args(argc, argv, ["Mandelbrot", "Julia"]);
	display = init_display("fract'ol");
	image = init_image(display);
	fractal = init_fractal(image, argv[1]);
	init_events(display, image);

	draw_mandelbrot(image, mandelbrot);
/*
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
