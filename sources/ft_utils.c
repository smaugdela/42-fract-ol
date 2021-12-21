/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:26:30 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/21 17:56:54 by smagdela         ###   ########.fr       */
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

int	ft_nblen(int nb)
{
	unsigned int	len;
	unsigned int	tmp_nb;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		++len;
		tmp_nb = -nb;
	}
	else
		tmp_nb = nb;
	while (tmp_nb)
	{
		++len;
		tmp_nb = tmp_nb / 10;
	}
	return (len);
}
