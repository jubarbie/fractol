/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:19:58 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/11 16:40:19 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "fractol.h"

void		init_pos(t_param *param)
{
	POSX = 0;
	POSY = 0;
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	ZOOM = 400;
	ITER = 20;
}

t_param		*init_param(int size_x, int size_y, char *title)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		exit(EXIT_FAILURE);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, size_x, size_y, title);
	WIN_X = size_x;
	WIN_Y = size_y;
	BPP = 24;
	SIZELINE = WIDTH * (BPP / 8);
	ENDIAN = 0;
	init_pos(param);
	COLOR = 255 / ITER << 0;
	return (param);
}
