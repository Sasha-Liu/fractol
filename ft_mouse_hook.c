/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:32:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/03 16:37:52 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mouse_hook(int button, int x, int y, void *param)
{
	t_window	*win;
	t_image		*img;
	

	win = (t_window *)param;
	img = win->img;
	if (button == 4)
		img->epsilon /= 1.01;
	else if (button == 5)
		img->epsilon *= 1.01;
	else
		return (0);

}

int	ft_new_x(t_image *img, int x)
{
	

}

int ft_new_y(t_image *img, int y)
{


}
