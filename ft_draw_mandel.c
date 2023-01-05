/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:57:37 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 13:55:46 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
static int	ft_is_mandel(double c_re, double c_im);
static void	ft_complex_square(double *real, double *img);
static void	ft_paint_pixel(t_image *img, int x, int y, int n);

/*	a and b is the top left corner of complex plane
 * 	epsilon is the distance between exch pixel
 */
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

static void	ft_paint_pixel(t_image *img, int x, int y, int n)
{
	int		index;
	double	factor;
	int		color;

	index = y * img->line_byte + x * img->pixel_bit / 8;
	factor = 255 / MAX_ITERA;
	if (n < MAX_ITERA / 2)
		color = ft_color_to_int(n * factor, 0, n * factor * 2);
	else
		color = ft_color_to_int(127, n * factor * 2, 255);
	if (img->endian == 1)
    {
        img->buffer[index + 0] = (color >> 24);
        img->buffer[index + 1] = (color >> 16) & 0xFF;
        img->buffer[index + 2] = (color >> 8) & 0xFF;
        img->buffer[index + 3] = (color) & 0xFF;
    }
    else if (img->endian == 0)
    {
        img->buffer[index + 0] = (color) & 0xFF;
        img->buffer[index + 1] = (color >> 8) & 0xFF;
        img->buffer[index + 2] = (color >> 16) & 0xFF;
        img->buffer[index + 3] = (color >> 24);
    }
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

static void	ft_complex_square(double *real, double *img)
{
	double	temp_real;
	double	temp_img;

	temp_real = (*real) * (*real) - (*img) * (*img);
	temp_img = 2 * (*real) * (*img);
	*real = temp_real;
	*img = temp_img;
}
