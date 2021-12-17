/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:26:30 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/17 14:56:15 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	complex_magnitude(t_complex z)
{
	return (sqrt(pow(z.re, 2) + pow(z.im, 2)));
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
