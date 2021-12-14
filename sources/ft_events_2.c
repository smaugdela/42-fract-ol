/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:57:13 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/14 15:56:31 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	red_cross_handler(t_image *image)
{
	free_n_destroy(image, image->display);
	ft_putstr_fd("\nClosing...\nThanks for using fract'ol!\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
