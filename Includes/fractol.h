/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 10:48:32 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/30 19:13:55 by jubarbie         ###   ########.fr       */
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

# define OPT_REF "p"
# define OPT param->opt
# define P (OPT & (1 << 0))
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
# define C_R param->c_r
# define C_I param->c_i
# define Z_R param->z_r
# define Z_I param->z_i
# define FRCT param->frct
# define NAME param->name
# define V param->v
# define COLOR param->color
# define BLU 255 / ITER << 0
# define GRE 255 / ITER << 8
# define RED 255 / ITER << 16
# define BLG 255 << (ITER % 8)
# define PUR 255 / ITER << 0 | 255 / ITER << 16
# define RAI 255 / (ITER % 27 + 1) << 0 | 255 / (ITER % 3 + 1) << 16
# define PAL (param->palette)

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
	double	zoom;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		iter;
	int		color;
	int		*palette;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	void	(*frct)(int, int, struct s_param *);
	char	*name;
	char	opt;
	double	v;
}				t_param;

typedef	struct	s_pix
{
	int				x;
	int				y;
	unsigned int	color;
}				t_pix;

t_param			*init_param(int size_x, int size_y, char opt, char *name);
void			init_pos(t_param *param);

void			img_put_pixel(t_param *param, int x, int y, unsigned int color);

void			mandelbrot(int posx, int posy, t_param *param);
void			julia(int posx, int posy, t_param *param);
void			buddhabrot(int poxs, int posy, t_param *param);
void			newton(int poxs, int posy, t_param *param);

int				get_options(int ac, char **av, char *opt);

void			error_usage(void);
void			error_opt(char opt);

void			display_param(t_param *param);
void			display_toolbar(char *title, t_param *param);

int				ft_key(int keycode, t_param *param);
int				ft_mouse(int button, int x, int y, t_param *param);

#endif
