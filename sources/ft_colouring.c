/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:49:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/22 18:22:14 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pixel_color(int x, int y, t_image *image)
{
	char	*pixel;

	if (x > WIN_W || x < 0 || y > WIN_H || y < 0)
		return (42);
	pixel = image->addr + (y * image->size_line + x * (image->bpp / 8));
	return (*(int *)pixel);
}

int	color_bnw(int n, int max_iter)
{
	(void)n;
	(void)max_iter;
	return(0xffffff);
}

int color_r(int n, int max_iter)
{
	int	R;

	R = -255 * ((float)n / (float)max_iter) + 255;
	return (0x010000 * R);
}

int color_g(int n, int max_iter)
{
	int	G;

	G = -255 * ((float)n / (float)max_iter) + 255;
	return (0x000100 * G);
}

int color_b(int n, int max_iter)
{
	int	B;

	B = -255 * ((float)n / (float)max_iter) + 255;
	return (B);
}
