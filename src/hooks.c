/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:36:00 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/09 15:46:01 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//mlx_hook(w->window, 4, 0, mouse_press_hook, w);
//mlx_hook(w->window, 5, 0, mouse_release_hook, w);
//mlx_hook(w->window, 6, 0, motion_hook, w);
//mlx_hook(w->window, 12, 0, expose_hook, w);
void	ft_set_hook(t_window *w)
{
	mlx_do_key_autorepeaton(w->mlx);
	mlx_hook(w->win, 2, 0, ft_key_down_hook, w);
	mlx_hook(w->win, 3, 0, ft_key_up_hook, w);
	mlx_hook(w->win, 6, 0, ft_julia_motion_hook, w);
	mlx_hook(w->win, 17, 0, ft_destroy_hook, w);
	mlx_mouse_hook(w->win, ft_zoom_hook, w);
}

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
	ft_draw(img);
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

//int ft_destroy_hook(void *param)
int	ft_destroy_hook(void)
{
	exit(0);
}
