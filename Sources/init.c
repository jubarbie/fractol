/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:19:58 by jubarbie          #+#    #+#             */
/*   Updated: 2016/04/19 11:43:17 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"
#include "fdf.h"

void		init_pos(t_param *param)
{
	POSX = 0;
	POSY = 0;
	ZOOM = 400;
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
	return (param);
}
