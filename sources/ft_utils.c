/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:30:00 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/10 13:39:59 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error(const char* ft_name)
{
	ft_putstr_fd("Error: ", 2);
	perror(ft_name);
	exit(EXIT_FAILURE);
}

void destroy_n_free(t_display *display)
{
	mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	mlx_destroy_display(display->mlx_ptr);
	free(display->mlx_ptr);
}

int	ft_mean(int a, int b)
{
	return ((a + b) / 2);
}
