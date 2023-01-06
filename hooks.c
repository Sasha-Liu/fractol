/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:36:00 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 11:04:24 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_up_hook(int keycode, void *param);
int	ft_destroy_hook(void *param);
int	ft_key_down_hook(int keycode, void *param);

//mlx_hook(w->window, 4, 0, mouse_press_hook, w);
//mlx_hook(w->window, 5, 0, mouse_release_hook, w);
//mlx_hook(w->window, 6, 0, motion_hook, w);
//mlx_hook(w->window, 12, 0, expose_hook, w);
void	ft_set_hook(t_window *w)
{
	mlx_do_key_autorepeaton(w->mlx);
	mlx_hook(w->win, 2, 0, ft_key_down_hook, w);
	mlx_hook(w->win, 3, 0, ft_key_up_hook, w);
	mlx_hook(w->win, 17, 0, ft_destroy_hook, w);
	mlx_mouse_hook(w->win, ft_zoom_hook, w);
}

/* left = 123
 * down = 125
 * right = 124
 * up  = 126
 */
int	ft_key_down_hook(int keycode, void *param)
{
	t_window	*win;
	t_image		*img;

	win = (t_window *)param;
	img = win->img;
	if (keycode == 123)
		img->a -= img->epsilon * 5;
	else if (keycode == 125)
		img->b -= img->epsilon * 5;
	else if (keycode == 124)
		img->a += img->epsilon * 5;
	else if (keycode == 126)
		img->b += img->epsilon * 5;
	else
		return (0);
	ft_draw(img, img->a, img->b);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	return (0);
}

int	ft_key_up_hook(int keycode, void *param)
{
	t_window	*win;
	t_image		*img;

	if (keycode != 53)
		return (0);
	win = (t_window *)param;
	img = win->img;
	mlx_destroy_image(win->mlx, img->img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}

int	ft_destroy_hook(void *param)
{
	exit(0);
}
