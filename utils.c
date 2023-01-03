/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:42:37 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/03 15:51:04 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_to_int(double red, double green, double blue)
{
	int	color;
	color = 0;
	color = color | (int)blue;
	color = color | (int)green << 8;
	color = color | (int)red << 16;
	return (color);
}
