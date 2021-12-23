/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:13:58 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/23 13:42:40 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom_in(t_image *img)
{
	img->fractal.max_im -= 0.2 * (img->fractal.max_im - img->fractal.min_im);
	img->fractal.min_im += 0.2 * (img->fractal.max_im - img->fractal.min_im);
	img->fractal.max_re -= 0.2 * (img->fractal.max_re - img->fractal.min_re);
	img->fractal.min_re += 0.2 * (img->fractal.max_re - img->fractal.min_re);
	img->fractal.render = TRUE;
}

void	zoom_out(t_image *img)
{
	img->fractal.max_im += 0.2 * (img->fractal.max_im - img->fractal.min_im);
	img->fractal.min_im -= 0.2 * (img->fractal.max_im - img->fractal.min_im);
	img->fractal.max_re += 0.2 * (img->fractal.max_re - img->fractal.min_re);
	img->fractal.min_re -= 0.2 * (img->fractal.max_re - img->fractal.min_re);
	img->fractal.render = TRUE;
}
