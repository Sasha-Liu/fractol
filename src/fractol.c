/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:02:48 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 14:17:57 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_err(int argc, char **argv, t_image *img);

int	main(int argc, char **argv)
{
	t_window	win;
	t_image		img;

	if (ft_init_win_img(&win, &img) == NULL)
		return (0);
	//if (ft_err(argc, argv, &img))
	//	return (0);
	ft_set_hook(&win);
	ft_draw(&img);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}

int	ft_err(int argc, char **argv, t_image *img)
{
	if (argc == 1)
	{
		ft_printf("Example of usage:\n ./fractol mandelbrot\n");
		ft_printf("./fractol julia 0.353 0.288\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		if (argc > 2)
		{
			ft_printf("Too many argument\n");
			return (1);
		}
		img->which = 0;
	}	
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
		{
			ft_printf("Usage: julia 0.353 0.288\n");
			return (1);
		}
		img->which = 1;
		img->julia_a = 0.353;
		img->julia_b = 0.288;
	}
	if (ft_strncmp(argv[1], "burning ship", 13) == 0)
	{
		if (argc > 2)
		{
			ft_printf("Too many argument\n");
			return (1);
		}
		img->which = 2;
	}
	return (0);
}
