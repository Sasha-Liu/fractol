/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:02:48 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 16:36:04 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_window	win;
	t_image		img;

	if (ft_init_win_img(&win, &img) == NULL)
		return (0);
	if (ft_parse_input(argc, argv, &img) == 1)
	{
		mlx_destroy_image(win.mlx, img.img);
		mlx_destroy_window(win.mlx, win.win);
		return (0);
	}
	ft_set_hook(&win);
	ft_draw(&img);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}

int	ft_parse_input(int argc, char **argv, t_image *img)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		img->which = 0;
		return (0);
	}
	else if (argc == 2 && ft_strncmp(argv[1], "burning ship", 13) == 0)
	{
		img->which = 2;
		return (0);
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		img->which = 1;
		img->julia_a = ft_atod(argv[2]);
		img->julia_b = ft_atod(argv[3]);
		return (0);
	}
	ft_printf("Usage: ./fractol FRACTAL_NAME \n  Example:\n");
	ft_printf("\t./fractol mandelbrot\n\t./fractol julia 0.33 0.28");
	ft_printf("\n\t./fractol \"burning ship\"\n");
	return (1);
}

//convert asci to double
double	ft_atod(char *str)
{
	double	sum;
	double	power;
	int		i;

	sum = 0;
	power = 1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		sum = sum * 10 + (double)(str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (sum);
	else
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		power = power / 10;
		sum += power * (double)(str[i] - '0');
		i++;
	}
	return (sum);
}
