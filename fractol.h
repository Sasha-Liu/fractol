/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/03 16:02:38 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx/mlx.h"
#include <stddef.h>
#include <stdlib.h>

# define WIDTH	1000
# define HEIGHT 600
# define SCALE	1.001
# define MAX_ITERA	50

typedef struct s_image t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_image	*img;
}	t_window;

typedef struct s_image
{
	void		*img;
	char		*buffer;
	int			pixel_bit;
	int			line_byte;
	int			endian;
	double		x_cent;
	double		y_cent;
	double		epsilon;
	t_window	*win;
}	t_image;

void	*ft_init_win_img(t_window *win, t_image *img);
void	ft_set_hook(t_window *w);
void	ft_draw_mandel(t_image *img);
int		ft_color_to_int(double red, double green, double blue);


#endif
