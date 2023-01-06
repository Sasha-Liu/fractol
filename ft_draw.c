/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:41:52 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/06 13:14:34 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//create THRD_NUM threads
void	ft_draw(t_image *img)
{
	pthread_t		thread_id[THRD_NUM];
	t_img_thread	img_thread[THRD_NUM];
	int				i;
	void			*ret;

	i = 0;
	while (i < THRD_NUM)
	{
		img_thread[i].img = img;
		img_thread[i].num = i;
		if (pthread_create(&(thread_id[i]), NULL, ft_routine, &(img_thread[i])) != 0)
		{
			perror("pthread_create");
			mlx_destroy_image(img->win->mlx, img->img);
			mlx_destroy_window(img->win->mlx, img->win->win);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < THRD_NUM)
	{
		pthread_join(thread_id[i], &ret);
		i++;
	}
}

void	*ft_routine(void *param)
{
	t_img_thread	*img_thread;
	double			min_re;
	double			max_im;

	img_thread = (t_img_thread *)param;
	min_re = img_thread->img->a + (WIDTH / THRD_NUM) * (img_thread->num) * img_thread->img->epsilon;
	max_im = img_thread->img->b;
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


