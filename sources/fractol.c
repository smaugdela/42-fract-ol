/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/21 14:16:43 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*fract_sets(void **ft_ptr, int i)
{
	char		*sets[3];
	void		*ft_list[3];

	sets[0] = "Mandelbrot";
	sets[1] = "Julia";
	sets[2] = NULL;
	ft_list[0] = &draw_mandelbrot;
	ft_list[1] = &draw_julia;
	ft_list[2] = NULL;
	if (i >= 0 && i <= 2)
	{
		*ft_ptr = ft_list[i];
		return (sets[i]);
	}
	return (NULL);
}

static void	*check_args(int argc, char *set)
{
	int		i;
	void	*ft;
	char	*available_sets;

	i = 0;
	ft = NULL;
	available_sets = fract_sets(&ft, i);
	while (argc == 2 && available_sets != NULL)
	{
		if (ft_strncmp(set, available_sets,
			max(ft_strlen(set), ft_strlen(available_sets))) == 0)
		{
			return (ft);
		}
		++i;
		available_sets = fract_sets(&ft, i);
	}
	ft_putstr_fd("Usage: ./fractol <name of fractal set>\n", 1);
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

static t_fractal	init_fractal(t_image *image, void *draw_ft)
{
	t_fractal	fractal;
	t_complex	z;

	fractal.max_re = 2;
	fractal.min_re = -2;
	fractal.max_im = 2;
	fractal.min_im = -2;
	fractal.details_iter = MAX_ITER;
	z.re = 0.0;
	z.im = 0.0;
	fractal.param = z;
	fractal.render = TRUE;
	fractal.display_ui = FALSE;
	fractal.image = image;
	fractal.draw_ft = draw_ft;
	image->fractal = fractal;
	return (fractal);
}

int	main(int argc, char **argv)
{
	t_display	*display;
	t_image		*image;
	t_fractal	fractal;
	void 		(*draw_ft)(t_fractal, int, int, int, int);
	
	draw_ft = check_args(argc, argv[1]);
	display = init_display("fract'ol");
	image = init_image(display);
	fractal = init_fractal(image, draw_ft);
	init_events(display, image);
	mlx_loop(display->mlx_ptr);
	free_n_destroy(image, display);
	ft_putstr_fd("Stopping...\n\033[0;32mThanks for using fract'ol!\033[0m\n", 1);
	return (0);
}
