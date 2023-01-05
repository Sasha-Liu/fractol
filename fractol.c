/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:02:48 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 13:01:10 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_window	win;
	t_image		img;

	if (ft_init_win_img(&win, &img) == NULL)
		return (0);
	ft_set_hook(&win);
	ft_draw_mandel(&img, img.a, img.b);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}


