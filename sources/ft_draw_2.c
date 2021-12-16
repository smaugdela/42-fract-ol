/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:23:31 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 19:09:19 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rectangle	*build_rectangle(int coord[2], int dim[2], int color, t_bool bord)
{
	t_rectangle	*rectangle;

	rectangle = malloc(1 * sizeof(t_rectangle));
	if (rectangle == NULL)
		return (NULL);
	if (coord[0] < 0)
		rectangle->x = 0;
	else
		rectangle->x = coord[0];
	if (coord[1] < 0)
		rectangle->y = 0;
	else
		rectangle->y = coord[1];
	if (dim[0] < 0)
		rectangle->width = 0;
	else
		rectangle->width = dim[0];
	if (dim[1] < 0)
		rectangle->height = 0;
	else
		rectangle->height = dim[1];
	rectangle->color = color;
	rectangle->border_only = bord;
	return (rectangle);
}

void	draw_rectangle(t_image *image, t_rectangle *rectangle)
{
	int	i;
	int	j;

	if (rectangle == NULL)
	{
		free_n_destroy(image, image->display);
		ft_error("malloc");
	}
	i = rectangle->x - 1;
	while (++i < WIN_WIDTH && i < rectangle->x + rectangle->width)
	{
		j = rectangle->y - 1;
		while (++j < WIN_HEIGHT && j < rectangle->y + rectangle->height)
		{
			if (rectangle->border_only == TRUE
				&& (i == rectangle->x || i == rectangle->x + rectangle->width)
				&& (j == rectangle->y || j == rectangle->y + rectangle->height))
				draw_pixel(image, i, j, rectangle->color);
			else if (rectangle->border_only == FALSE)
				draw_pixel(image, i, j, rectangle->color);
		}
	}
	free(rectangle);
}

void	real_axis(t_image *image)
{
	int	y;
	int	y_sym;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		y_sym = WIN_HEIGHT;
		while (y < WIN_HEIGHT / 2)
		{
			draw_pixel(image, x, y_sym, get_pixel_color(x, y, image));
			++y;
			--y_sym;
		}
		++x;
	}
}
