/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:47:22 by jubarbie          #+#    #+#             */
/*   Updated: 2016/04/19 14:38:25 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"
#include "math.h"
#include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

void	move_img(int keycode, t_param *param)
{
	if (keycode == 0)
		POSX -= 20;
	if (keycode == 2)
		POSX += 20;
	if (keycode == 13)
		POSY -= 20;
	if (keycode == 1)
		POSY += 20;
}

int		ft_key(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 49)
		init_pos(param);
	if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1)
		move_img(keycode, param);
	if (keycode == 78)
		ZOOM /= (ZOOM > 0) ? 1.6 : 1;
	if (keycode == 69)
		ZOOM *= 1.5;
	return (0);
}

int		main(void)
{
	t_param	*param;

	param = init_param(1800, 1200, "fractol");
	white_screen(param);
	create_img(param);
	mlx_string_put(MLX, WIN, 10, 15, 0x00000000, "MANDELBROT");
	mlx_expose_hook(WIN, create_img, param);
	mlx_loop_hook(MLX, create_img, param);
	mlx_key_hook(WIN, ft_key, param);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key,  param);
	mlx_loop(MLX);
	free(param);
	return (0);
}
