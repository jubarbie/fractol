/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:41:13 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/05 22:27:08 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	Z_I /= 3;
	Z_R /= 3;
}

void		sierpinski(int posx, int posy, t_param *param)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			Z_I = abs(x - posx);
			Z_R = abs(y - posy);
			i = -1;
			while (((int)Z_I % 3 != 1 || (int)Z_R % 3 != 1) && ++i < ITER)
				fract_calc(param);
			if (i != ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * PAL[COLOR]));
		}
	}
}
