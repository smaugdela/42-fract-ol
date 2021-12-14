/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:24:29 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/14 17:58:55 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define WIN_WIDTH  1920
# define WIN_HEIGHT	1080

# define TRUE	1
# define FALSE	0

# define MAX_ITER	30

typedef int8_t	t_bool;

/* Data structures for mlx */
typedef struct s_display {
	void	*mlx_ptr;
	void	*win_ptr;
	t_bool	drawing;
}	t_display;

typedef struct s_image {
	t_display	*display;
	void		*image_ptr;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}	t_image;

/* Geometry structures */
typedef struct s_circle {
	int		x_c;
	int		y_c;
	double	r;
	int		color;
}	t_circle;

/* Fractals structures */
typedef struct s_complex {
	float	re;
	float	im;
}	t_complex;

typedef	struct s_fractal {
	int		(*ft_fractal)(t_complex);
	float	max_re;
	float	max_im;
	float	min_re;
	float	min_im;
}	t_fractal;

/* Data initialisation and destruction for mlx */
void		ft_error(const char *ft_name);
void		free_n_destroy(t_image *image, t_display *display);
t_image		*init_image(t_display *display);
t_display	*init_display(char *win_name);

/* Geometry drawing functions */
int			get_pixel_color(int x, int y, t_image *image);
int			draw_pixel(t_image *image, int x, int y, int color);
int			clear_window(t_image *image, int color);
t_circle	*build_circle(int x, int y, double r, int color);
int			draw_circle(t_image *image, t_circle *circle);
void		draw_fractal(t_image *image, t_fractal fractal);

/* Events handling functions */
int			loop_handler(t_image *image);
int			keys_handler(int key_sym, t_image *image);
int			keys_rev_handler(int key_sym, t_image *image);
int			pointer_handler(int x, int y, t_image *image);
int			button_handler(int button, int x, int y, t_image *image);
int			button_rev_handler(int button, int x, int y, t_image *image);
int			red_cross_handler(t_image *image);

/* Fractals definitions */
int			ft_mandelbrot(t_complex c);

#endif
