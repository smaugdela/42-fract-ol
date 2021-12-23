/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:24:29 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/23 19:59:27 by smagdela         ###   ########.fr       */
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

# define WIN_W  800
# define WIN_H	800

# define TRUE	1
# define FALSE	0

# define MAX_ITER	15

typedef int8_t	t_bool;

/* Fractals structures */
typedef struct s_complex {
	float	re;
	float	im;
}	t_complex;

typedef struct s_fractal {
	float		max_re;
	float		max_im;
	float		min_re;
	float		min_im;
	int			max_iter;
	t_complex	param;
	t_bool		render;
	t_bool		display_ui;
	void		*image;
	void		(*draw_ft)(struct s_fractal, int *, int *);
	int			(*color_ft)(int, int);
}	t_fractal;

/* Data structures for mlx */
typedef struct s_display {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_display;

typedef struct s_image {
	t_display	*display;
	t_fractal	fractal;
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

/* Parsing */
void		*fract_sets(char *set);
t_fractal	check_args(int argc, char **argv);
void		ft_error(const char *ft_name);

/* Data initialisation and destruction for mlx */
void		free_n_destroy(t_image *image, t_display *display);
t_image		*init_image(t_display *display);
t_display	*init_display(char *win_name);

/* Events handling functions */
int			loop_handler(t_image *image);
int			keys_handler(int key_sym, t_image *image);
int			pointer_handler(int x, int y, t_image *image);
int			button_handler(int button, int x, int y, t_image *image);
int			red_cross_handler(t_image *image);
void		zoom_in(t_image *img);
void		zoom_out(t_image *img);
void		reset(t_image *image);

/* Drawing functions */
void		draw_pixel(t_image *image, int x, int y, int color);
int			clear_window(t_image *image, int color);
t_circle	*build_circle(int coord[2], double r, int color, t_bool bord);
void		draw_circle(t_image *image, t_circle *circle);
t_rectangle	*build_rectangle(int coord[2], int dim[2], int color, t_bool bord);
void		draw_rectangle(t_image *image, t_rectangle *rectangle);
void		draw_ui(t_image *image);

/* Colouring functions */
int			get_pixel_color(int x, int y, t_image *image);
int			color_monochrome(int n, char color);
int			color_bnw(int n, int max_iter);
int			color_grayscale(int n, int max_iter);
int			color_r(int n, int max_iter);
int			color_g(int n, int max_iter);
int			color_b(int n, int max_iter);
int			color_multi(int n, int max_iter);

/* Fractals definitions */
void		draw_mandelbrot(t_fractal para, int *xrange, int *yrange);
void		draw_julia(t_fractal para, int *xrange, int *yrange);

/* Toolbox */
float		complex_magnitude(t_complex z);
int			max(int a, int b);
t_bool		ft_c_in_charset(char c, char *charset);
t_bool		ft_is_charset(const char *str, char *charset);
float		ft_atof(char *str);

/*
Escape-codes colors
GREEN \033[0;32m
RED \033[1;31m
Magenta \033[0;35m
NC	\033[0m
*/

#endif
