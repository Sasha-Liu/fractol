/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:49:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 16:29:27 by hsliu            ###   ########.fr       */
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

/*	a and b means a + bi, 
 *	it represent the top left corner of the complex plane   
 */
typedef struct s_image
{
	void		*img;
	char		*buffer;
	int			pixel_bit;
	int			line_byte;
	int			endian;
	double		a;
	double		b;
	double		epsilon;
	t_window	*win;
}	t_image;

void	*ft_init_win_img(t_window *win, t_image *img);
void	ft_set_hook(t_window *w);
void	ft_draw_mandel(t_image *img, double a, double b);
int		ft_color_to_int(double red, double green, double blue);


#endif
