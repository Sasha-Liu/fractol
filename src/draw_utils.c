/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:01:22 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 14:15:33 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_color_to_int(double red, double green, double blue)
{
	int	color;

	color = 0;
	color = color | (int)blue;
	color = color | (int)green << 8;
	color = color | (int)red << 16;
	return (color);
}

void	ft_paint_pixel(t_image *img, int x, int y, int n)
{
	int		index;
	double	factor;
	int		color;

	index = y * img->line_byte + x * img->pixel_bit / 8;
	factor = 255 / MAX_ITERA;
	if (n < MAX_ITERA / 2)
		color = ft_color_to_int(0, n * factor * 2, n * factor * 2);
	else
		color = ft_color_to_int(n * factor * 2, 255, 255);
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

void	ft_complex_square(double *real, double *img)
{
	double	temp_real;
	double	temp_img;

	temp_real = (*real) * (*real) - (*img) * (*img);
	temp_img = 2 * (*real) * (*img);
	*real = temp_real;
	*img = temp_img;
}
