/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:02:13 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/31 17:46:50 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	float tmp;

	tmp = Z_R;
	Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
	Z_I = 2 * Z_I * tmp + C_I;
}

void		julia(int posx, int posy, t_param *param)
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
			C_R = 0.285 + V;
			C_I = 0.01 + V / 10;
			Z_R = (x - posx) / ZOOM + X1;
			Z_I = (y - posy) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0
							| i * PAL[COLOR]));
		}
	}
}

void		mandelbrot(int posx, int posy, t_param *param)
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
			C_R = (x - posx) / ZOOM + X1;
			C_I = (y - posy) / ZOOM + Y1;
			Z_R = 0;
			Z_I = V * 2;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * PAL[COLOR]));
		}
	}
}

void		newton(int posx, int posy, t_param *param)
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
			C_R = -0.00508;
			C_I = 0.33136;
			Z_R = (x - posx) / ZOOM + X1;
			Z_I = (y - posy) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + C_R * C_I < 1 && ++i < ITER)
			{
				tmp = Z_R;
				Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
				Z_I = 3 * Z_I * tmp + C_I;
			}
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * PAL[COLOR]));
		}
	}
}

void		buddhabrot(int posx, int posy, t_param *param)
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

void		sierpinski(int posx, int posy, t_param *param)
{
	int	x;
	int	y;
	int	xd;
	int yd;
	int	i;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			xd = x - posx;
			yd = y - posy;
			i = -1;
			while ((xd > 0 || yd > 0) && ++i < ITER)
			{
				if (xd % 3 == 1 && yd % 3 == 1)
					break ;
				xd /= 3;
				yd /= 3;
			}
			if (i != ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * PAL[COLOR]));
		}
	}

}
