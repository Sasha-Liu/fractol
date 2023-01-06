/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 16:02:36 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"
# include <pthread.h>

# define WIDTH	600
# define HEIGHT 400
# define SCALE	1.09
# define MAX_ITERA	200
# define THRD_NUM	8

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

typedef struct s_img_thread{
	t_image		*img;
	pthread_t	id;
	int			num;
}t_img_thread;

/****** manage input and errors  ******/
int		ft_parse_input(int argc, char **argv, t_image *img);
double	ft_atod(char *str);

/****** initialize ******/
void	*ft_init_win_img(t_window *win, t_image *img);

/****** event hooks ******/
void	ft_set_hook(t_window *w);
int		ft_zoom_hook(int button, int x, int y, void *param);
int		ft_motion_hook(int x, int y, void *param);
int		ft_key_up_hook(int keycode, void *param);
int		ft_key_down_hook(int keycode, void *param);
int		ft_destroy_hook(void);

/****** drawing function  ******/
void	ft_draw(t_image *img);
void	*ft_routine(void *arg);
void	ft_draw_routine(t_image *img, double min_re, double max_im, int i);
int		ft_is_which(double c_re, double c_im, t_image *img);
int		ft_is_julia(double c_re, double c_im, t_image *img);
int		ft_is_mandel(double c_re, double c_im);
int		ft_is_burning_ship(double c_re, double c_im);

/******  helper function  ******/
int		ft_color_to_int(double red, double green, double blue);
void	ft_paint_pixel(t_image *img, int x, int y, int n);
void	ft_complex_square(double *real, double *img);

#endif