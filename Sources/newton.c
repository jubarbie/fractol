/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:35:14 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/06 17:38:51 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	long double tmp;
	
	tmp = Z_R;
	C_R = 3.0 * ((Z_R * Z_R - Z_I * Z_I) * (Z_R * Z_R - Z_I * Z_I) + 4.0 * Z_R * Z_R * Z_I * Z_I) + V;
	if (C_R == 0.0)
		C_R = 0.00001;
	Z_R = (2.0 / 3.0) * Z_R + (Z_R * Z_R - Z_I * Z_I) / C_R;
	Z_I = (2.0 / 3.0) * Z_I - 2.0 * tmp * Z_I / C_R;
}

void		newton(int posx, int posy, t_param *param)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			Z_R = (x - posx) / ZOOM - 0.5;
			Z_I = (y - posy) / ZOOM + 0.866;
			i = -1;
			while (++i < ITER)
				fract_calc(param);	
			if (Z_R > 0.0)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							ITER * PAL[COLOR]));
			else if (Z_R < -0.3 && Z_I > 0.0)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							ITER * PAL[COLOR + 1]));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							ITER * PAL[COLOR + 2]));
		}
	}
}
