/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:30:00 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/13 15:21:33 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error(const char* ft_name)
{
	ft_putstr_fd("Error: ", 2);
	perror(ft_name);
	exit(EXIT_FAILURE);
}

void free_n_destroy(t_image *image, t_display *display)
{
	if (image && image->image_ptr)
		mlx_destroy_image(image->display->mlx_ptr, image->image_ptr);
	if (image)
	{
		free(image);
		image = NULL;
	}
	if (display && display->win_ptr)
		mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	if (display)
	{
		free(display->win_ptr);
		display->win_ptr = NULL;
	}
	if (display && display->mlx_ptr)
	{
		mlx_destroy_display(display->mlx_ptr);
		free(display->mlx_ptr);
	}
	if (display)
	{
		free(display);
		display = NULL;
	}
}

t_image	*init_image(t_display *display)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (image == NULL)
	{
		free(display);
		ft_error("malloc");
	}
	if (image == NULL || display == NULL)
	{
		free_n_destroy(image, display);
		ft_error("init_image");
	}
	image->display = display;
	image->image_ptr = mlx_new_image(display->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	image->addr = mlx_get_data_addr(image->image_ptr,
		&image->bpp, &image->size_line, &image->endian);
	if (image == NULL || image->image_ptr == NULL || image->addr == NULL)
	{
		free_n_destroy(image, display);
		ft_error("mlx_new_image");
	}
	return (image);
}

int8_t	ft_mean(int8_t a, int8_t b)
{
	return ((a + b) / 2);
}