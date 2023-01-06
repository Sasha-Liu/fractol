/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:32:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 15:40:40 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//only mouse scroll event
//because obviously, the mouse position x and y are calculated diffrently
//depending on whether you click or scroll the mouse
int	ft_zoom_hook(int button, int x, int y, void *param)
{
	t_window	*win;
	t_image		*img;
	double		new_ep;
	double		old_ep;

	win = (t_window *)param;
	img = win->img;
	old_ep = img->epsilon;
	if (button == 5)
		new_ep = old_ep / SCALE;
	else if (button == 4)
		new_ep = old_ep * SCALE;
	else
		return (0);
	img->a = img->a + x * old_ep - x * new_ep;
	img->b = img->b - (HEIGHT - y) * old_ep + (HEIGHT - y) * new_ep;
	img->epsilon = new_ep;
	ft_draw(img);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	return (0);
}

//only trigger when drawing julia set
int	ft_motion_hook(int x, int y, void *param)
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
