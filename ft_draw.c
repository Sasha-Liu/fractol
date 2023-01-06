/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:41:52 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 11:18:35 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_image *img, double min_re, double max_im)
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
			n = ft_is_which(c_re, c_im, img);
			ft_paint_pixel(img, x, y, n);
			x++;
		}
		y++;
	}
}
