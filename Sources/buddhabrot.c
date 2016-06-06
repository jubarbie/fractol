/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:40:25 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/06 16:59:51 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	long double	tmp;

	tmp = Z_R;
	Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
	Z_I = 2 * Z_I * tmp + C_I;
}

void		buddhabrot(int posx, int posy, t_param *param)
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
			C_R = (x - posx) / ZOOM + X1;
			C_I = (y - posy) / ZOOM + Y1;
			Z_R = 0;
			Z_I = 0;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i != ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * PAL[COLOR]));
		}
	}
}
