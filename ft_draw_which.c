/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_which.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:19:30 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 14:54:44 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	ft_is_mandel(double c_re, double c_im);
static int	ft_is_julia(double c_re, double c_im, t_image *img);

void	ft_draw_which(t_image *img, double min_re, double max_im)
{
	if (img->which == 0)
		ft_draw_mandel(img, min_re, max_im);
	else if (img->which == 1)
		ft_draw_julia(img, min_re, max_im);
}

void	ft_draw_julia(t_image *img, double min_re, double max_im)
{
	double	c_re;
	double	c_im;
	int		x;
	int		y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c_im = max_im - y * img->epsilon;
		while (x < WIDTH)
		{
			c_re = min_re + x * img->epsilon;
			n = ft_is_julia(c_re, c_im, img);
			ft_paint_pixel(img, x, y, n);
			x++;
		}
		y++;
	}
}

void	ft_draw_mandel(t_image *img, double min_re, double max_im)
{
	double	c_re;
	double	c_im;
	int		x;
	int		y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c_im = max_im - y * img->epsilon;
		while (x < WIDTH)
		{
			c_re = min_re + x * img->epsilon;
			n = ft_is_mandel(c_re, c_im);
			ft_paint_pixel(img, x, y, n);
			x++;
		}
		y++;
	}
}

static int	ft_is_julia(double c_re, double c_im, t_image *img)
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

static int	ft_is_mandel(double c_re, double c_im)
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
