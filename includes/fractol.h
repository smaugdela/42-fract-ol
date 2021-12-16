/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:24:29 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 16:00:36 by smagdela         ###   ########.fr       */
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

# define MAX_ITER	10

typedef int8_t	t_bool;

/* Fractals structures */
typedef struct s_complex {
	float	re;
	float	im;
}	t_complex;

typedef	struct s_fractal {
	float	max_re;
	float	max_im;
	float	min_re;
	float	min_im;
	int		details_iter;
	float	zoom;
}	t_fractal;

/* Data structures for mlx */
typedef struct s_display {
	void	*mlx_ptr;
	void	*win_ptr;
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
	t_bool	border_only;
}	t_circle;

typedef struct s_rectangle {
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
	t_bool	border_only;
}	t_rectangle;

/* Data initialisation and destruction for mlx */
void		ft_error(const char *ft_name);
void		free_n_destroy(t_image *image, t_display *display);
t_image		*init_image(t_display *display);
t_display	*init_display(char *win_name);

/* Events handling functions */
int			loop_handler(t_image *image);
int			keys_handler(int key_sym, t_image *image);
int			keys_rev_handler(int key_sym, t_image *image);
int			pointer_handler(int x, int y, t_image *image);
int			button_handler(int button, int x, int y, t_image *image);
int			button_rev_handler(int button, int x, int y, t_image *image);
int			red_cross_handler(t_image *image);

/* Drawing functions */
int			draw_pixel(t_image *image, int x, int y, int color);
int			clear_window(t_image *image, int color);
t_circle	*build_circle(int x, int y, double r, int color);
int			draw_circle(t_image *image, t_circle *circle);
t_circle	*build_rectangle(int x, int y, double r, int color);
int			draw_rectangle(t_image *image, t_rectangle *rectangle);

/* Colouring functions */
int			get_pixel_color(int x, int y, t_image *image);
int			color_monochrome(int n, char color);

/* Fractals definitions */
float		complex_magnitude(t_complex z);
float		ft_mandelbrot(t_complex c);
float		ft_julia(t_complex c, t_fractal julia);
void		draw_mandelbrot(t_image *image, t_fractal fractal);
void		draw_julia(t_image *image, t_fractal fractal);

#endif
