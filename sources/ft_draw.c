/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:56:01 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 15:07:53 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pixel_color(int x, int y, t_image *image)
{
	char	*pixel;

	pixel = image->addr + (y * image->size_line + x * (image->bpp / 8));
	return (*(int *)pixel);
}

int	draw_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	pixel = image->addr + (y * image->size_line + x * (image->bpp / 8));
	color = mlx_get_color_value(image->display->mlx_ptr, color);
	i = image->bpp;
	while (i >= 8)
	{
		i -= 8;
		if (image->endian == 1)
			*pixel = (color >> i) & 255;
		else
			*pixel = (color >> (image->bpp - i - 8)) & 255;
		++pixel;
	}
	return (0);
}

int	clear_window(t_image *image, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = -1;
		while (++j < WIN_HEIGHT)
		{
			if (get_pixel_color(i, j, image) > 0)
				draw_pixel(image, i, j, color);
		}
	}
	mlx_put_image_to_window(image->display->mlx_ptr,
		image->display->win_ptr, image->image_ptr, 0, 0);
	return (0);
}

t_circle	*build_circle(int x, int y, double r, int color)
{
	t_circle	*circle;

	circle = NULL;
	circle = malloc(1 * sizeof(t_circle));
	if (circle == NULL)
		return (NULL);
	circle->x_c = x;
	circle->y_c = y;
	circle->r = r;
	circle->color = color;
	return (circle);
}

int	draw_circle(t_image *image, t_circle *circle)
{
	int	i;
	int	j;

	if (circle == NULL)
	{
		free_n_destroy(image, image->display);
		ft_error("malloc");
	}
	i = circle->x_c - circle->r - 1;
	while (++i < WIN_WIDTH)
	{
		j = circle->y_c - circle->r - 1;
		while (++j < WIN_HEIGHT)
		{
			if (sqrt(pow(circle->x_c - i, 2) + pow(circle->y_c - j, 2))
				<= circle->r)
				draw_pixel(image, i, j, circle->color);
		}
	}
	free(circle);
	return (0);
}
