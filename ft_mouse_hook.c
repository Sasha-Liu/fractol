/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:32:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 16:38:12 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mouse_hook(int button, int x, int y, void *param)
{
	t_window	*win;
	t_image		*img;
	double		new_ep;
	double		old_ep;

	win = (t_window *)param;
	img = win->img;
	old_ep = img->epsilon;
	if (button == 4)
		new_ep = old_ep / 1.01;
	else if (button == 5)
		new_ep = old_ep * 1.01;
	else
		return (0);
	img->a = img->a + x * (old_ep - new_ep);
	img->b = img->b - y * (old_ep - new_ep);
	img->epsilon = new_ep;
	ft_draw_mandel(img, img->a, img->b);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	return (0);
}
