/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:24:29 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/10 18:19:34 by smagdela         ###   ########.fr       */
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

typedef int8_t	t_bool;

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

typedef struct s_circle {
	int		x_c;
	int		y_c;
	double	r;
	int		color;
}	t_circle;

void		ft_error(const char* ft_name);
int			draw_pixel(t_image *image, int x, int y, int color);
int			draw_pixel_fusion(t_image *image, int x, int y, int color);
int			draw_circle(t_image *image, t_circle *circle);
t_circle	*build_circle(int x, int y, double r, int color);
void 		destroy_n_free(t_image *image, t_display *display);
int8_t		ft_mean(int8_t a, int8_t b);

#endif
