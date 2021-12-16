/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:56:01 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 17:35:46 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	draw_ui(t_image *image)
{
	int	color;

	color = get_pixel_color(WIN_WIDTH - 10, WIN_HEIGHT - 10, image);
	color = revert_color(color);
	mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
		x - 20, y - 20, color, "H for help");
}

t_circle	*build_circle(int coord[2], double r, int color, t_bool bord)
{
	t_circle	*circle;

	circle = malloc(1 * sizeof(t_circle));
	if (circle == NULL)
		return (NULL);
	if (coord[0] < 0)
		circle->x_c = 0;
	else
		circle->x_c = coord[0];
	if (coord[1] < 0)
		circle->y_c = 0;
	else
		circle->y_c = coord[1];
	if (r <= 0)
		circle->r = 1;
	else
		circle->r = r;
	circle->color = color;
	circle->border_only = bord;
	return (circle);
}

void	draw_circle(t_image *image, t_circle *circle)
{
	int	i;
	int	j;

	if (circle == NULL)
	{
		free_n_destroy(image, image->display);
		ft_error("malloc");
	}
	i = circle->x_c - circle->r - 1;
	while (++i < WIN_WIDTH && i < circle->x_c + circle->r)
	{
		j = circle->y_c - circle->r - 1;
		while (++j < WIN_HEIGHT && j < circle->y_c + circle->r)
		{
			if (circle->border_only == TRUE
				&& sqrt(pow(circle->x_c - i, 2) + pow(circle->y_c - j, 2))
				== circle->r)
				draw_pixel(image, i, j, circle->color);
			else if (circle->border_only == FALSE
				&& sqrt(pow(circle->x_c - i, 2) + pow(circle->y_c - j, 2))
				<= circle->r)
				draw_pixel(image, i, j, circle->color);
		}
	}
	free(circle);
}
