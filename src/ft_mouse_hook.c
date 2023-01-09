/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:32:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/09 15:44:21 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//only trigger when drawing julia set
//only trigger when right clip
int	ft_julia_motion_hook(int x, int y, void *param)
{
	t_window	*win;
	t_image		*img;

	win = (t_window *)param;
	img = win->img;
	if (img->which != 1 || y < 10)
		return (0);
	img->julia_a = img->a + x * img->epsilon;
	img->julia_b = img->b - y * img->epsilon;
	ft_draw(img);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	return (0);
}
