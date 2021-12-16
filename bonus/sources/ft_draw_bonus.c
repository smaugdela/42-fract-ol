/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:06:18 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/16 15:07:21 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	color_continuous(float nu)
{
	unsigned char	color_bytes[4];
	int				color;
	float			freq;

	freq = 0.008;
	color_bytes[0] = (unsigned char)255;
	color_bytes[1] = (unsigned char)((sin(freq * nu + 3.14 / 2) + 1) * 127.5);
	color_bytes[2] = (unsigned char)((sin(freq * nu + 3.14) + 1) * 127.5);
	color_bytes[3] = (unsigned char)((sin(freq * nu + 0) + 1) * 127.5);
	color = 0;
	color = color | color_bytes[0] << 24;
	color = color | color_bytes[1] << 16;
	color = color | color_bytes[2] << 8;
	color = color | color_bytes[3];
	return (color);
}
