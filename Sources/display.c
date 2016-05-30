/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 12:38:18 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/13 19:25:34 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void	white_screen(t_param *param)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			mlx_pixel_put(MLX, WIN, x, y, 0x00FFFFFF);
	}
}

void		draw_circle(int x, int y, char c, t_param *param)
{
	int	r;
	int	i;
	int	j;
	int	color;

	r = 20;
	j = y - 1;
	if (c == '1')
		color = 0x000000E0;
	if (c == '2')
		color = 0x0000E000;
	if (c == '3')
		color = 0x00E00000;
	while (++j <= y + r * 2)
	{
		i = x - 1;
		while (++i <= x + r * 2)
			if (sqrt(ft_power_two(abs(x + r - i)) +
						ft_power_two(abs(y + r - j))) < r)
				mlx_pixel_put(MLX, WIN, i, j, color);
	}
	mlx_string_put(MLX, WIN, x + 15, y + r / 2, 0x00FFFFFF, &c);
}

void		display_param(t_param *param)
{
	int	x;
	int	y;

	if (P)
	{
		y = 54;
		while (++y < 146)
		{
			x = 14;
			while (++x < 151)
				mlx_pixel_put(MLX, WIN, x, y, 0x0000000);
		}
		mlx_string_put(MLX, WIN, 20, 60, 0x00FFFFFF, "x1: ");
		mlx_string_put(MLX, WIN, 100, 60, 0x00FFFFFF, ft_itoa(X1));
		mlx_string_put(MLX, WIN, 20, 80, 0x00FFFFFF, "x2: ");
		mlx_string_put(MLX, WIN, 100, 80, 0x00FFFFFF, ft_itoa(X2));
		mlx_string_put(MLX, WIN, 20, 100, 0x00FFFFFF, "iter: ");
		mlx_string_put(MLX, WIN, 100, 100, 0x00FFFFFF, ft_itoa(ITER));
		mlx_string_put(MLX, WIN, 20, 120, 0x00FFFFFF, "zoom: ");
		mlx_string_put(MLX, WIN, 100, 120, 0x00FFFFFF, ft_itoa(ZOOM / 100));
	}
}

void		display_toolbar(char *title, t_param *param)
{
	white_screen(param);
	mlx_string_put(MLX, WIN, 10, 15, 0x00000000, title);
	draw_circle(WIN_X - 40, 7, '3', param);
	draw_circle(WIN_X - 60, 7, '2', param);
	draw_circle(WIN_X - 80, 7, '1', param);
}