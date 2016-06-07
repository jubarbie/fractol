/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 10:48:32 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/07 10:43:14 by jubarbie         ###   ########.fr       */
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

# define OPT_REF "mpz"
# define OPT param->opt
# define M (OPT & (1 << 0))
# define P (OPT & (1 << 1))
# define Z (OPT & (1 << 2))
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
# define ITER_MAX param->iter_max
# define C_R param->c_r
# define C_I param->c_i
# define Z_R param->z_r
# define Z_I param->z_i
# define FRCT param->frct
# define NAME param->name
# define V param->v
# define COLOR param->color
# define BNW 255 / ITER << 0 | 255 / ITER << 8 | 255 / ITER << 16
# define BLU 255 / ITER << 0
# define GRE 255 / ITER << 8
# define RED 255 / ITER << 16
# define BLG 255 << (ITER % 8)
# define PUR 255 / ITER << 0 | 255 / ITER << 16
# define RAI 255 / (ITER) << 0 ^ 255 / (ITER / 2) << 8 ^ 255 / (ITER / 3) << 16
# define PSY 0x00FFFFFF / ITER
# define PAL (param->palette)

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	int			win_x;
	int			win_y;
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
	int			bpp;
	int			sizeline;
	int			endian;
	char		*img_addr;
	long double	zoom;
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	int			iter;
	int			iter_max;
	int			color;
	int			*palette;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	void		(*frct)(int, int, struct s_param *);
	char		*name;
	char		opt;
	long double	v;
}				t_param;

typedef	struct	s_pix
{
	int				x;
	int				y;
	unsigned int	color;
}				t_pix;

t_param			*init_param(int size_x, int size_y, char opt, char *name);
void			free_param(t_param *param);
void			init_pos(char *name, t_param *param);

void			img_put_pixel(t_param *param, int x, int y, unsigned int color);

void			mandelbrot(int posx, int posy, t_param *param);
void			julia(int posx, int posy, t_param *param);
void			buddhabrot(int poxs, int posy, t_param *param);
void			brain(int poxs, int posy, t_param *param);
void			burningship(int poxs, int posy, t_param *param);
void			newton(int poxs, int posy, t_param *param);
void			sierpinski(int posx, int posy, t_param *param);

int				get_options(int ac, char **av, char *opt);

void			error_usage(void);
void			error_opt(char opt);

void			display_param(t_param *param);
void			display_toolbar(char *title, t_param *param);

int				ft_key(int keycode, t_param *param);
int				ft_mouse(int button, int x, int y, t_param *param);
int				ft_mouse_motion(int x, int y, t_param *param);

#endif
