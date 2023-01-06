/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_which.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:17:51 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 13:54:39 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_is_which(double c_re, double c_im, t_image *img)
{
	if (img->which == 0)
		return (ft_is_mandel(c_re, c_im));
	else if (img->which == 1)
		return (ft_is_julia(c_re, c_im, img));
	else if (img->which == 2)
		return (ft_is_burning_ship(c_re, c_im));
	return (0);
}

int	ft_is_julia(double c_re, double c_im, t_image *img)
{
	int		n;
	double	z_re;
	double	z_im;

	n = 0;
	z_re = c_re;
	z_im = c_im;
	while (n < MAX_ITERA)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (n);
		ft_complex_square(&z_re, &z_im);
		z_re += img->julia_a;
		z_im += img->julia_b;
		n++;
	}
	if (z_re * z_re + z_im * z_im > 4)
		return (n);
	return (0);
}

int	ft_is_mandel(double c_re, double c_im)
{
	int		n;
	double	z_re;
	double	z_im;

	n = 0;
	z_re = 0;
	z_im = 0;
	while (n < MAX_ITERA)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (n);
		ft_complex_square(&z_re, &z_im);
		z_re += c_re;
		z_im += c_im;
		n++;
	}
	if (z_re * z_re + z_im * z_im > 4)
		return (n);
	return (0);
}

int	ft_is_burning_ship(double c_re, double c_im)
{
	int		n;
	double	z_re;
	double	z_im;

	n = 0;
	z_re = 0;
	z_im = 0;
	while (n < MAX_ITERA)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (n);
		z_re = fabs(z_re);
		z_im = fabs(z_im);
		ft_complex_square(&z_re, &z_im);
		z_re += c_re;
		z_im += c_im;
		n++;
	}
	if (z_re * z_re + z_im * z_im > 4)
		return (n);
	return (0);
}
