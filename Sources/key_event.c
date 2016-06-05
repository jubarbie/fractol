/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:47:10 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/05 22:56:33 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_img(int keycode, t_param *param)
{
	if (keycode == 0 || keycode == 123)
		POSX -= 10;
	if (keycode == 2 || keycode == 124)
		POSX += 10;
	if (keycode == 13 || keycode == 126)
		POSY -= 10;
	if (keycode == 1 || keycode == 125)
		POSY += 10;
}

static void	change_color(int keycode, t_param *param)
{
	if (keycode == 18)
		COLOR = 0;
	if (keycode == 19)
		COLOR = 1;
	if (keycode == 20)
		COLOR = 2;
	if (keycode == 21)
		COLOR = 3;
	if (keycode == 23)
		COLOR = 4;
	if (keycode == 22)
		COLOR = 5;
}

static void	zoom(int keycode, t_param *param)
{
	if (keycode == 78 && ZOOM > 0)
	{
		ZOOM /= 1.5;
		POSX /= 1.5;
		POSY /= 1.5;
		ITER -= 3;
	}
	if (keycode == 69 && ZOOM < 900000000)
	{
		ZOOM *= 1.5;
		ITER += 3;
		POSX *= 1.5;
		POSY *= 1.5;
	}
}

int			ft_key(int keycode, t_param *param)
{
	move_img(keycode, param);
	change_color(keycode, param);
	zoom(keycode, param);
	if (keycode == 53)
	{
		free_param(param);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49)
		init_pos(NAME, param);
	if (keycode == 17)
		ITER += (ITER < 500) ? 1 : 0;
	if (keycode == 5)
		ITER -= (ITER > 2) ? 1 : 0;
	if (keycode == 35)
		OPT ^= (P) ? P : ~P;
	if (keycode == 24)
		V += (V < 5) ? 0.001 : 0;
	if (keycode == 27)
		V -= (V > -5) ? 0.001 : 0;
	if (keycode == 38)
		init_pos("julia", param);
	if (keycode == 46)
		init_pos("mandelbrot", param);
	return (0);
}
