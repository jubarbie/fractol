/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:02:13 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/12 18:19:35 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int posx, int posy, t_param *param)
{
	int		x;
	int		y;
	int		i;
	float	tmp;

	X1 = -1;
	X2 = 1;
	Y1 = -1.2;
	Y2 = 1.2;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			C_R = 0.285;
			C_I = 0.01;
			Z_R = (x - posx) / ZOOM + X1;
			Z_I = (y - posy) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
			{
				tmp = Z_R;
				Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
				Z_I = 2 * Z_I * tmp + C_I;
			}
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000
							| i * COLOR));
		}
	}
}

void	mandelbrot(int posx, int posy, t_param *param)
{
	int		x;
	int		y;
	int		i;
	float	tmp;

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
			{
				tmp = Z_R;
				Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
				Z_I = 2 * Z_I * tmp + C_I;
			}
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000
							| i * COLOR));
		}
	}
}
