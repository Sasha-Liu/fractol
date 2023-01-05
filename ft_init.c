/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:09:19 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 13:23:11 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_init_win_img(t_window *win, t_image *img)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (NULL);
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fract-ol");
	if (win->win == NULL)
		return (NULL);
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
	{
		mlx_destroy_window(win->mlx, win->win);
		return (NULL);
	}
	img->buffer = mlx_get_data_addr(img->img, &(img->pixel_bit),
			&(img->line_byte), &(img->endian));
	img->a = -2;
	img->b = 1;
	img->epsilon = 0.003;
	win->img = img;
	img->win = win;
	return (win->mlx);
}
