/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 14:36:50 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>

# define WIDTH	1000
# define HEIGHT 800
# define SCALE	1.09
# define MAX_ITERA	50
# define mandelbrot 0
# define julia 1

typedef struct s_image	t_image;

typedef struct s_window{
	void	*mlx;
	void	*win;
	t_image	*img;
}t_window;

/*	a and b means a + bi, 
 *	it represent the top left corner of the complex plane   
 */
typedef struct s_image{
	void		*img;
	int			which;
	double		julia_a;
	double		julia_b;
	char		*buffer;
	int			pixel_bit;
	int			line_byte;
	int			endian;
	double		a;
	double		b;
	double		epsilon;
	t_window	*win;
}t_image;

/****** initialize ******/
void	*ft_init_win_img(t_window *win, t_image *img);

/****** event hooks ******/
void	ft_set_hook(t_window *w);
int		ft_mouse_hook(int button, int x, int y, void *param);

/****** drawing function  ******/
void	ft_draw_which(t_image *img, double min_re, double max_im);
void	ft_draw_mandel(t_image *img, double min_re, double max_im);
void	ft_draw_julia(t_image *img, double min_re, double max_im);

/******  helper function  ******/
int		ft_color_to_int(double red, double green, double blue);
void	ft_paint_pixel(t_image *img, int x, int y, int n);
void	ft_complex_square(double *real, double *img);

#endif
