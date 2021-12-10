/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:56:01 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/10 18:25:06 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Not Working
int draw_pixel_fusion(t_image *image, int x, int y, int color)
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
			*pixel = ft_mean((color >> i) & 255, *pixel);
		else
			*pixel = ft_mean((color >> (image->bpp - i - 8)) & 255, *pixel);
		++pixel;
	}
	return (0);
}
*/

int draw_pixel(t_image *image, int x, int y, int color)
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

t_circle	*build_circle(int x, int y, double r, int color)
{
    t_circle    *circle;

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
		destroy_n_free(image, image->display);
		ft_error("malloc");
	}
	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = -1;
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
