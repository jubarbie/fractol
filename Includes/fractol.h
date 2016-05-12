/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 10:48:32 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/12 19:03:49 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include <OpenCL/opencl.h>
# include "mlx.h"
# include "libft.h"

# define MLX param->mlx
# define WIN param->win
# define POSX param->pos_x
# define POSY param->pos_y
# define WIN_X param->win_x
# define WIN_Y param->win_y
# define WIDTH param->width
# define HEIGHT param->height
# define BPP param->bpp
# define SIZELINE param->sizeline
# define ENDIAN param->endian
# define IMG param->img
# define IMG_ADDR param->img_addr
# define ZOOM param->zoom
# define X1 param->x1
# define X2 param->x2
# define Y1 param->y1
# define Y2 param->y2
# define ITER param->iter
# define COLOR param->color
# define C_R param->c_r
# define C_I param->c_i
# define Z_R param->z_r
# define Z_I param->z_i
# define FRCT param->frct

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_x;
	int		win_y;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*img_addr;
	float	zoom;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		iter;
	int		color;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	void	(*frct)(int, int, struct s_param *);
}				t_param;

typedef	struct	s_pix
{
	int				x;
	int				y;
	unsigned int	color;
}				t_pix;

t_param			*init_param(int size_x, int size_y, char *title);
void			white_screen(t_param *param);
void			init_pos(t_param *param);
void			img_put_pixel(t_param *param, int x, int y, unsigned int color);
int				create_img(t_param *param);
void			mandelbrot(int posx, int posy, t_param *param);
void			julia(int posx, int posy, t_param *param);

void			error_usage(void);

#endif
