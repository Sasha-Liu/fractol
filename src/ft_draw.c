/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:41:52 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 13:53:48 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_err(t_image *img);

//create THRD_NUM threads
void	ft_draw(t_image *img)
{
	t_img_thread	img_thrd[THRD_NUM];
	int				i;
	void			*ret;
	int				err;

	i = 0;
	while (i < THRD_NUM)
	{
		img_thrd[i].img = img;
		img_thrd[i].num = i;
		err = pthread_create(&(img_thrd[i].id), 0, ft_routine, &(img_thrd[i]));
		if (err != 0)
		{
			ft_err(img);
		}
		i++;
	}
	i = 0;
	while (i < THRD_NUM)
	{
		pthread_join(img_thrd[i].id, &ret);
		i++;
	}
}

static void	ft_err(t_image *img)
{
	perror("pthread_create");
	mlx_destroy_image(img->win->mlx, img->img);
	mlx_destroy_window(img->win->mlx, img->win->win);
	exit(0);
}

void	*ft_routine(void *param)
{
	t_img_thread	*img_thread;
	t_image			*img;
	double			min_re;
	double			max_im;

	img_thread = (t_img_thread *)param;
	img = img_thread->img;
	min_re = img->a + (WIDTH / THRD_NUM) * (img_thread->num) * img->epsilon;
	max_im = img->b;
	ft_draw_routine(img_thread->img, min_re, max_im, img_thread->num);
	return (NULL);
}

//need to modify x
//it does not start from 0
void	ft_draw_routine(t_image *img, double min_re, double max_im, int i)
{
	double	c_re;
	double	c_im;
	int		x;
	int		y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c_im = max_im - y * img->epsilon;
		while (x < WIDTH / THRD_NUM)
		{
			c_re = min_re + x * img->epsilon;
			n = ft_is_which(c_re, c_im, img);
			ft_paint_pixel(img, x + (WIDTH / THRD_NUM) * i, y, n);
			x++;
		}
		y++;
	}
}
